// Copyright (c) 2014-2015 The AsturCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "utildialog.h"
#include "ui_utildialog.h"

#include "walletmodel.h"
#include "asturcoinunits.h"
#include "addressbookpage.h"
#include "optionsmodel.h"
#include "guiutil.h"
#include "receiverequestdialog.h"
#include "addresstablemodel.h"
#include "recentrequeststablemodel.h"

#include <QAction>
#include <QCursor>
#include <QMessageBox>
#include <QTextDocument>
#include <QScrollBar>

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

    if(model && model->getOptionsModel())
    {
        connect(model->getOptionsModel(), SIGNAL(displayUnitChanged(int)), this, SLOT(updateDisplayUnit()));
        updateDisplayUnit();

        ui->recentRequestsView->setModel(model->getRecentRequestsTableModel());
        ui->recentRequestsView->setAlternatingRowColors(true);
        ui->recentRequestsView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->recentRequestsView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        ui->recentRequestsView->horizontalHeader()->resizeSection(RecentRequestsTableModel::Date, 130);
        ui->recentRequestsView->horizontalHeader()->resizeSection(RecentRequestsTableModel::Label, 120);
#if QT_VERSION < 0x050000
        ui->recentRequestsView->horizontalHeader()->setResizeMode(RecentRequestsTableModel::Message, QHeaderView::Stretch);
#else
        ui->recentRequestsView->horizontalHeader()->setSectionResizeMode(RecentRequestsTableModel::Message, QHeaderView::Stretch);
#endif
        ui->recentRequestsView->horizontalHeader()->resizeSection(RecentRequestsTableModel::Amount, 100);

        model->getRecentRequestsTableModel()->sort(RecentRequestsTableModel::Date, Qt::DescendingOrder);
    }
}

UtilDialog::~UtilDialog()
{
    delete ui;
}

void UtilDialog::accept()
{
    clear();
}

void UtilDialog::on_receiveButton_clicked()
{
    if(!model || !model->getOptionsModel() || !model->getAddressTableModel() || !model->getRecentRequestsTableModel())
        return;

    QString address;
    QString label = ui->reqLabel->text();
    if(ui->reuseAddress->isChecked())
    {
        /* Choose existing receiving address */
        AddressBookPage dlg(AddressBookPage::ForSelection, AddressBookPage::ReceivingTab, this);
        dlg.setModel(model->getAddressTableModel());
        if(dlg.exec())
        {
            address = dlg.getReturnValue();
            if(label.isEmpty()) /* If no label provided, use the previously used label */
            {
                label = model->getAddressTableModel()->labelForAddress(address);
            }
        } else {
            return;
        }
    } else {
        /* Generate new receiving address */
        address = model->getAddressTableModel()->addRow(AddressTableModel::Receive, label, "");
    }
    SendCoinsRecipient info(address, label,
        ui->reqAmount->value(), ui->reqMessage->text());
    ReceiveRequestDialog *dialog = new ReceiveRequestDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModel(model->getOptionsModel());
    dialog->setInfo(info);
    dialog->show();
    clear();

    /* Store request for later reference */
    model->getRecentRequestsTableModel()->addNewRequest(info);
}

void UtilDialog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        // press return -> submit form
        if (ui->reqLabel->hasFocus() || ui->reqAmount->hasFocus() || ui->reqMessage->hasFocus())
        {
            event->ignore();
            on_receiveButton_clicked();
            return;
        }
    }

    this->QDialog::keyPressEvent(event);
}

