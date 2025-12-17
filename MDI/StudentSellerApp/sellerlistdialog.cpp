#include "sellerlistdialog.h"
#include "ui_sellerlistdialog.h"

SellerListDialog::SellerListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerListDialog),
    model(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Список Sellers");
}

SellerListDialog::~SellerListDialog()
{
    delete model;
    delete ui;
}

void SellerListDialog::setDatabase(QSqlDatabase db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("Sellers");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    // Встановити заголовки
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Прізвище");
    model->setHeaderData(2, Qt::Horizontal, "Ім'я");
    model->setHeaderData(3, Qt::Horizontal, "По батькові");
    model->setHeaderData(4, Qt::Horizontal, "Адреса");
    model->setHeaderData(5, Qt::Horizontal, "Номер рахунку");
    
    model->select();
    
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void SellerListDialog::updateList()
{
    if (model) {
        model->select();
        ui->label_count->setText(QString("Всього: %1").arg(model->rowCount()));
    }
}
