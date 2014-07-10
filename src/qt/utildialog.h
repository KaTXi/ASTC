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

namespace Ui {
    class UtilDialog;
}
class WalletModel;
class OptionsModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog for requesting payment of asturcoins */
class UtilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UtilDialog(QWidget *parent = 0);
    ~UtilDialog();

    void setModel(WalletModel *model);

public slots:
    void accept();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::UtilDialog *ui;
    WalletModel *model;

private slots:
    void on_receiveButton_clicked();
};

#endif // UTILDIALOG_H
