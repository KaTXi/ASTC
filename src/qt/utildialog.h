// Copyright (c) 2014-2015 The AsturCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UTILDIALOG_H
#define UTILDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QMenu>
#include <QPoint>
#include <QVariant>
#include <QTime>

namespace Ui {
    class UtilDialog;
}
class WalletModel;
class OptionsModel;
class ClientModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog for getting info of asturcoins */
class UtilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UtilDialog(QWidget *parent = 0);
    ~UtilDialog();

    void setModel(WalletModel *model);
	enum MessageClass {
        MC_ERROR,
        MC_DEBUG,
        CMD_REQUEST,
        CMD_REPLY,
        CMD_ERROR
    };
public slots:
    void message(int category, const QString &message, bool html = false);
	
protected:
    
signals:
    // For RPC command executor
    void cmdRequest(const QString &command);
	
private:
    Ui::UtilDialog *ui;
    WalletModel *model;

private slots:
	void startExecutor();
	void handleSelectionChanged(int index);
};

#endif // UTILDIALOG_H
