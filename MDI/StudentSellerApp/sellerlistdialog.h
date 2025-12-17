#ifndef SELLERLISTDIALOG_H
#define SELLERLISTDIALOG_H

#include <QDialog>
#include <QVector>
#include "Seller.h"

namespace Ui {
class SellerListDialog;
}

class SellerListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SellerListDialog(QWidget *parent = nullptr);
    ~SellerListDialog();
    
    void setSellers(const QVector<Seller*>& sellers);
    void updateList(const QVector<Seller*>& sellers);

private:
    Ui::SellerListDialog *ui;
};

#endif // SELLERLISTDIALOG_H
