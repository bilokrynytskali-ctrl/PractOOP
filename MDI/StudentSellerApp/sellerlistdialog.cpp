#include "sellerlistdialog.h"
#include "ui_sellerlistdialog.h"

SellerListDialog::SellerListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerListDialog)
{
    ui->setupUi(this);
    setWindowTitle("Список Sellers");
}

SellerListDialog::~SellerListDialog()
{
    delete ui;
}

void SellerListDialog::setSellers(const QVector<Seller*>& sellers)
{
    updateList(sellers);
}

void SellerListDialog::updateList(const QVector<Seller*>& sellers)
{
    ui->listWidget->clear();
    
    for (const auto& seller : sellers) {
        QString info = QString("ID: %1 - %2")
                        .arg(seller->getId())
                        .arg(QString::fromStdString(seller->getFullName()));
        ui->listWidget->addItem(info);
    }
    
    ui->label_count->setText(QString("Всього: %1").arg(sellers.size()));
}
