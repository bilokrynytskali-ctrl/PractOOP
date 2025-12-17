#include "studentlistdialog.h"
#include "ui_studentlistdialog.h"

StudentListDialog::StudentListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentListDialog),
    model(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Список Students");
}

StudentListDialog::~StudentListDialog()
{
    delete model;
    delete ui;
}

void StudentListDialog::setDatabase(QSqlDatabase db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("Students");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    // Встановити заголовки
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Прізвище");
    model->setHeaderData(2, Qt::Horizontal, "Ім'я");
    model->setHeaderData(3, Qt::Horizontal, "По батькові");
    model->setHeaderData(4, Qt::Horizontal, "Адреса");
    model->setHeaderData(5, Qt::Horizontal, "Телефон");
    model->setHeaderData(6, Qt::Horizontal, "Факультет");
    model->setHeaderData(7, Qt::Horizontal, "Курс");
    model->setHeaderData(8, Qt::Horizontal, "Група");
    
    model->select();
    
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void StudentListDialog::updateList()
{
    if (model) {
        model->select();
        ui->label_count->setText(QString("Всього: %1").arg(model->rowCount()));
    }
}
