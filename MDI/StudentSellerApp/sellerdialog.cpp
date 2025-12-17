#include "sellerdialog.h"
#include "ui_sellerdialog.h"
#include <QMessageBox>
#include <QInputDialog>

SellerDialog::SellerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerDialog)
{
    ui->setupUi(this);
    setWindowTitle("Створити Seller");
}

SellerDialog::~SellerDialog()
{
    delete ui;
}

void SellerDialog::on_pushButton_addProduct_clicked()
{
    bool ok;
    QString product = QInputDialog::getText(this, "Додати товар",
                                           "Назва товару:", 
                                           QLineEdit::Normal, "", &ok);
    if (ok && !product.isEmpty()) {
        ui->listWidget_products->addItem(product);
    }
}

void SellerDialog::on_pushButton_create_clicked()
{
    // Перевірка заповнення полів
    if (ui->lineEdit_lastName->text().isEmpty() ||
        ui->lineEdit_firstName->text().isEmpty() ||
        ui->lineEdit_patronymic->text().isEmpty() ||
        ui->lineEdit_address->text().isEmpty() ||
        ui->lineEdit_accountNumber->text().isEmpty()) {
        
        QMessageBox::warning(this, "Помилка", 
                            "Заповніть всі поля!");
        return;
    }
    
    // Створити Seller
    int id = ui->lineEdit_id->text().toInt();
    Seller* seller = new Seller(
        id,
        ui->lineEdit_lastName->text().toStdString(),
        ui->lineEdit_firstName->text().toStdString(),
        ui->lineEdit_patronymic->text().toStdString(),
        ui->lineEdit_address->text().toStdString(),
        ui->lineEdit_accountNumber->text().toStdString()
    );
    
    // Додати товари
    for (int i = 0; i < ui->listWidget_products->count(); i++) {
        seller->addProduct(ui->listWidget_products->item(i)->text().toStdString());
    }
    
    emit sellerCreated(seller);
    
    QMessageBox::information(this, "Успіх", "Seller створено!");
    accept();
}
