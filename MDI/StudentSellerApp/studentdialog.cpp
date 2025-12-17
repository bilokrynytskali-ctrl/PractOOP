#include "studentdialog.h"
#include "ui_studentdialog.h"
#include <QMessageBox>

StudentDialog::StudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    setWindowTitle("Створити Student");
}

StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::on_pushButton_create_clicked()
{
    // Перевірка заповнення полів
    if (ui->lineEdit_lastName->text().isEmpty() ||
        ui->lineEdit_firstName->text().isEmpty() ||
        ui->lineEdit_patronymic->text().isEmpty() ||
        ui->lineEdit_address->text().isEmpty() ||
        ui->lineEdit_phone->text().isEmpty() ||
        ui->lineEdit_faculty->text().isEmpty() ||
        ui->lineEdit_group->text().isEmpty()) {
        
        QMessageBox::warning(this, "Помилка", 
                            "Заповніть всі поля!");
        return;
    }
    
    // Створити Student
    int id = ui->lineEdit_id->text().toInt();
    Student* student = new Student(
        id,
        ui->lineEdit_lastName->text().toStdString(),
        ui->lineEdit_firstName->text().toStdString(),
        ui->lineEdit_patronymic->text().toStdString(),
        ui->lineEdit_address->text().toStdString(),
        ui->lineEdit_phone->text().toStdString(),
        ui->lineEdit_faculty->text().toStdString(),
        ui->spinBox_course->value(),
        ui->lineEdit_group->text().toStdString()
    );
    
    emit studentCreated(student);
    
    QMessageBox::information(this, "Успіх", "Student створено!");
    accept();
}
