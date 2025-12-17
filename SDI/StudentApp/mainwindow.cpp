#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , student(nullptr)
{
    ui->setupUi(this);
    
    // Налаштувати заголовок вікна
    setWindowTitle("Student Management");
}

MainWindow::~MainWindow()
{
    if (student) {
        delete student;
    }
    delete ui;
}

void MainWindow::on_pushButton_create_clicked()
{
    // Перевірка заповнення обов'язкових полів
    if (ui->lineEdit_lastName->text().isEmpty() ||
        ui->lineEdit_firstName->text().isEmpty() ||
        ui->lineEdit_patronymic->text().isEmpty() ||
        ui->lineEdit_address->text().isEmpty() ||
        ui->lineEdit_phone->text().isEmpty() ||
        ui->lineEdit_faculty->text().isEmpty() ||
        ui->lineEdit_group->text().isEmpty()) {
        
        QMessageBox::warning(this, "Помилка", 
                            "Будь ласка, заповніть всі обов'язкові поля!");
        return;
    }
    
    // Видалити попередній об'єкт
    if (student) {
        delete student;
        student = nullptr;
    }
    
    // Отримати дані з полів
    int id = ui->lineEdit_id->text().toInt();
    std::string lastName = ui->lineEdit_lastName->text().toStdString();
    std::string firstName = ui->lineEdit_firstName->text().toStdString();
    std::string patronymic = ui->lineEdit_patronymic->text().toStdString();
    std::string address = ui->lineEdit_address->text().toStdString();
    std::string phone = ui->lineEdit_phone->text().toStdString();
    std::string faculty = ui->lineEdit_faculty->text().toStdString();
    int course = ui->spinBox_course->value();
    std::string group = ui->lineEdit_group->text().toStdString();
    
    // Створити новий об'єкт
    student = new Student(id, lastName, firstName, patronymic, 
                         address, phone, faculty, course, group);
    
    // Повідомлення про успіх
    QString message = QString(
        "Об'єкт Student створено успішно!\n\n"
        "ID: %1\n"
        "Прізвище: %2\n"
        "Ім'я: %3\n"
        "По батькові: %4\n"
        "Адреса: %5\n"
        "Телефон: %6\n"
        "Факультет: %7\n"
        "Курс: %8\n"
        "Група: %9"
    ).arg(id)
     .arg(QString::fromStdString(lastName))
     .arg(QString::fromStdString(firstName))
     .arg(QString::fromStdString(patronymic))
     .arg(QString::fromStdString(address))
     .arg(QString::fromStdString(phone))
     .arg(QString::fromStdString(faculty))
     .arg(course)
     .arg(QString::fromStdString(group));
    
    QMessageBox::information(this, "Успіх", message);
}

void MainWindow::on_actionCreate_triggered()
{
    on_pushButton_create_clicked();
}

void MainWindow::on_actionDisplay_triggered()
{
    if (!student) {
        QMessageBox::warning(this, "Помилка", 
                           "Об'єкт ще не створено! Спочатку створіть об'єкт.");
        return;
    }
    
    // Показати повідомлення про існуючий об'єкт
    int id = student->getId();
    QString fullName = QString::fromStdString(student->getFullName());
    
    QString message = QString("Існуючий об'єкт:\n\nID: %1\nПІБ: %2")
                        .arg(id)
                        .arg(fullName);
    
    QMessageBox::information(this, "Інформація", message);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
