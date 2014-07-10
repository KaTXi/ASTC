// Copyright (c) 2014-2015 The AsturCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "utildialog.h"
#include "ui_utildialog.h"

#include "walletmodel.h"
#include "asturcoinunits.h"
#include "optionsmodel.h"
#include "guiutil.h"

#include <QCursor>

UtilDialog::UtilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UtilDialog),
    model(0)
{
    ui->setupUi(this);

}

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

void UtilDialog::on_receiveButton_clicked()
{
    // if(!model || !model->getOptionsModel() || !model->getAddressTableModel() || !model->getRecentRequestsTableModel())
        // return;

    // QString address;
    // QString label = ui->reqLabel->text();
    // if(ui->reuseAddress->isChecked())
    // {
        // /* Choose existing receiving address */
        // AddressBookPage dlg(AddressBookPage::ForSelection, AddressBookPage::ReceivingTab, this);
        // dlg.setModel(model->getAddressTableModel());
        // if(dlg.exec())
        // {
            // address = dlg.getReturnValue();
            // if(label.isEmpty()) /* If no label provided, use the previously used label */
            // {
                // label = model->getAddressTableModel()->labelForAddress(address);
            // }
        // } else {
            // return;
        // }
    // } else {
        // /* Generate new receiving address */
        // address = model->getAddressTableModel()->addRow(AddressTableModel::Receive, label, "");
    // }
    // SendCoinsRecipient info(address, label,
        // ui->reqAmount->value(), ui->reqMessage->text());
    // ReceiveRequestDialog *dialog = new ReceiveRequestDialog(this);
    // dialog->setAttribute(Qt::WA_DeleteOnClose);
    // dialog->setModel(model->getOptionsModel());
    // dialog->setInfo(info);
    // dialog->show();
    // clear();

    // /* Store request for later reference */
    // model->getRecentRequestsTableModel()->addNewRequest(info);
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

