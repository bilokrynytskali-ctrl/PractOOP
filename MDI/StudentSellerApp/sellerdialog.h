#ifndef SELLERDIALOG_H
#define SELLERDIALOG_H

#include <QDialog>
#include "Seller.h"

namespace Ui {
class SellerDialog;
}

class SellerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SellerDialog(QWidget *parent = nullptr);
    ~SellerDialog();

signals:
    void sellerCreated(Seller* seller);

private slots:
    void on_pushButton_create_clicked();
    void on_pushButton_addProduct_clicked();

private:
    Ui::SellerDialog *ui;
};

#endif // SELLERDIALOG_H
