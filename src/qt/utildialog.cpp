// Copyright (c) 2014-2015 The AsturCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "utildialog.h"
#include "ui_utildialog.h"
#include "rpcserver.h"
#include "rpcclient.h"

#include "walletmodel.h"

#include "asturcoinunits.h"
#include "optionsmodel.h"
#include "guiutil.h"
#include "json/json_spirit_value.h"

#include <QCursor>
#include <QThread>

/* Object for executing console RPC commands in a separate thread.
*/
class RPCExecutorMine : public QObject
{
    Q_OBJECT

public slots:
    void request(const QString &command);

signals:
    void reply(int category, const QString &command);
};

#include "utildialog.moc"

/**
 * Split shell command line into a list of arguments. Aims to emulate \c bash and friends.
 *
 * - Arguments are delimited with whitespace
 * - Extra whitespace at the beginning and end and between arguments will be ignored
 * - Text can be "double" or 'single' quoted
 * - The backslash \c \ is used as escape character
 *   - Outside quotes, any character can be escaped
 *   - Within double quotes, only escape \c " and backslashes before a \c " or another backslash
 *   - Within single quotes, no escaping is possible and no special interpretation takes place
 *
 * @param[out]   args        Parsed arguments will be appended to this list
 * @param[in]    strCommand  Command line to split
 */
bool parseCommandLineMine(std::vector<std::string> &args, const std::string &strCommand)
{
    enum CmdParseState
    {
        STATE_EATING_SPACES,
        STATE_ARGUMENT,
        STATE_SINGLEQUOTED,
        STATE_DOUBLEQUOTED,
        STATE_ESCAPE_OUTER,
        STATE_ESCAPE_DOUBLEQUOTED
    } state = STATE_EATING_SPACES;
    std::string curarg;
    foreach(char ch, strCommand)
    {
        switch(state)
        {
        case STATE_ARGUMENT: // In or after argument
        case STATE_EATING_SPACES: // Handle runs of whitespace
            switch(ch)
            {
            case '"': state = STATE_DOUBLEQUOTED; break;
            case '\'': state = STATE_SINGLEQUOTED; break;
            case '\\': state = STATE_ESCAPE_OUTER; break;
            case ' ': case '\n': case '\t':
                if(state == STATE_ARGUMENT) // Space ends argument
                {
                    args.push_back(curarg);
                    curarg.clear();
                }
                state = STATE_EATING_SPACES;
                break;
            default: curarg += ch; state = STATE_ARGUMENT;
            }
            break;
        case STATE_SINGLEQUOTED: // Single-quoted string
            switch(ch)
            {
            case '\'': state = STATE_ARGUMENT; break;
            default: curarg += ch;
            }
            break;
        case STATE_DOUBLEQUOTED: // Double-quoted string
            switch(ch)
            {
            case '"': state = STATE_ARGUMENT; break;
            case '\\': state = STATE_ESCAPE_DOUBLEQUOTED; break;
            default: curarg += ch;
            }
            break;
        case STATE_ESCAPE_OUTER: // '\' outside quotes
            curarg += ch; state = STATE_ARGUMENT;
            break;
        case STATE_ESCAPE_DOUBLEQUOTED: // '\' in double-quoted text
            if(ch != '"' && ch != '\\') curarg += '\\'; // keep '\' for everything but the quote and '\' itself
            curarg += ch; state = STATE_DOUBLEQUOTED;
            break;
        }
    }
    switch(state) // final state
    {
    case STATE_EATING_SPACES:
        return true;
    case STATE_ARGUMENT:
        args.push_back(curarg);
        return true;
    default: // ERROR to end in one of the other states
        return false;
    }
}

void RPCExecutorMine::request(const QString &command)
{
    std::vector<std::string> args;
    if(!parseCommandLineMine(args, command.toStdString()))
    {
        emit reply(UtilDialog::CMD_ERROR, QString("Parse error: unbalanced ' or \""));
        return;
    }
    if(args.empty())
        return; // Nothing to do
    try
    {
        std::string strPrint;
        // Convert argument list to JSON objects in method-dependent way,
        // and pass it along with the method name to the dispatcher.
        json_spirit::Value result = tableRPC.execute(
            args[0],
            RPCConvertValues(args[0], std::vector<std::string>(args.begin() + 1, args.end())));

        // Format result reply
        if (result.type() == json_spirit::null_type)
            strPrint = "";
        else if (result.type() == json_spirit::str_type)
            strPrint = result.get_str();
        else
            strPrint = write_string(result, true);

        emit reply(UtilDialog::CMD_REPLY, QString::fromStdString(strPrint));
    }
    catch (json_spirit::Object& objError)
    {
        try // Nice formatting for standard-format error
        {
            int code = find_value(objError, "code").get_int();
            std::string message = find_value(objError, "message").get_str();
            emit reply(UtilDialog::CMD_ERROR, QString::fromStdString(message) + " (code " + QString::number(code) + ")");
        }
        catch(std::runtime_error &) // raised when converting to invalid type, i.e. missing code or message
        {   // Show raw JSON object
            emit reply(UtilDialog::CMD_ERROR, QString::fromStdString(write_string(json_spirit::Value(objError), false)));
        }
    }
    catch (std::exception& e)
    {
        emit reply(UtilDialog::CMD_ERROR, QString("Error: ") + QString::fromStdString(e.what()));
    }
}

UtilDialog::UtilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UtilDialog),
    model(0)
{
    ui->setupUi(this);
	
	QStringList list=(QStringList()<<""<<"Get Mining Info"<<"List Transactions"<<"Get Info"<<"Balance"<<"List Accounts"<<"Address Groupings"<<"Received by Account"<<"Received by Address"<<"List Unspent"<<"Best Block Hash"<<"Show Difficulty"<<"Show Hashes per Second"<<"Peers Info"<<"TX Out set Info");
	ui->comboBoxOpciones->addItems(list);
	
	connect(ui->comboBoxOpciones , SIGNAL(currentIndexChanged(int)),this,SLOT(handleSelectionChanged(int)));
	
	startExecutor();
}

void UtilDialog::handleSelectionChanged(int index)
{
	if (index==1) {
		message(CMD_REQUEST, "getmininginfo");
		emit cmdRequest("getmininginfo");
	} else if (index==2) {
		message(CMD_REQUEST, "listtransactions");
		emit cmdRequest("listtransactions");
	} else if (index==3) {
		message(CMD_REQUEST, "getinfo");
		emit cmdRequest("getinfo");
	} else if (index==4) {
		message(CMD_REQUEST, "getbalance");
		emit cmdRequest("getbalance");
	} else if (index==5) {
		message(CMD_REQUEST, "listaccounts");
		emit cmdRequest("listaccounts");
	} else if (index==6) {
		message(CMD_REQUEST, "listaddressgroupings");
		emit cmdRequest("listaddressgroupings");
	} else if (index==7) {
		message(CMD_REQUEST, "listreceivedbyaccount");
		emit cmdRequest("listreceivedbyaccount");
	} else if (index==8) {
		message(CMD_REQUEST, "listreceivedbyaddress");
		emit cmdRequest("listreceivedbyaddress");
	} else if (index==9) {
		message(CMD_REQUEST, "listunspent");
		emit cmdRequest("listunspent");
	} else if (index==10) {
		message(CMD_REQUEST, "getbestblockhash");
		emit cmdRequest("getbestblockhash");
	} else if (index==11) {
		message(CMD_REQUEST, "getdifficulty");
		emit cmdRequest("getdifficulty");
	} else if (index==12) {
		message(CMD_REQUEST, "gethashespersec");
		emit cmdRequest("gethashespersec");
	} else if (index==13) {
		message(CMD_REQUEST, "getpeerinfo");
		emit cmdRequest("getpeerinfo");
	} else if (index==14) {
		message(CMD_REQUEST, "gettxoutsetinfo");
		emit cmdRequest("gettxoutsetinfo");
	}

};
	
void UtilDialog::setModel(WalletModel *model)
{
    this->model = model;

}

UtilDialog::~UtilDialog()
{
    delete ui;
}

void UtilDialog::accept()
{
    //clear();
}

void UtilDialog::startExecutor()
{
    QThread *thread = new QThread;
    RPCExecutorMine *executor = new RPCExecutorMine();
    executor->moveToThread(thread);

    // Replies from executor object must go to this object
    connect(executor, SIGNAL(reply(int,QString)), this, SLOT(message(int,QString)));
    // Requests from this object must go to executor
    connect(this, SIGNAL(cmdRequest(QString)), executor, SLOT(request(QString)));

    // On stopExecutor signal
    // - queue executor for deletion (in execution thread)
    // - quit the Qt event loop in the execution thread
    connect(this, SIGNAL(stopExecutor()), executor, SLOT(deleteLater()));
    connect(this, SIGNAL(stopExecutor()), thread, SLOT(quit()));
    // Queue the thread for deletion (in this thread) when it is finished
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    // Default implementation of QThread::run() simply spins up an event loop in the thread,
    // which is what we want.
    thread->start();
}

void UtilDialog::message(int category, const QString &message, bool html)
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    QString out;
    out += "<table><tr><td class=\"time\" width=\"65\">" + timeString + "</td>";
    out += "<td  valign=\"middle\">";
    if(html)
        out += message;
    else
        out += GUIUtil::HtmlEscape(message, true);
    out += "</td></tr></table>";
    ui->textBrowser->append(out);
	LogPrintf("Out: %s\n", out.toUtf8().constData());
}

void UtilDialog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        // press return -> submit form
        //if (ui->reqLabel->hasFocus() || ui->reqAmount->hasFocus() || ui->reqMessage->hasFocus())
        //{
        //    event->ignore();
        //    on_receiveButton_clicked();
        //    return;
        //}
    }

    this->QDialog::keyPressEvent(event);
}

