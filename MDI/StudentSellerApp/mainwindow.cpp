#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentdialog.h"
#include "sellerdialog.h"
#include <QMessageBox>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , studentListDialog(nullptr)
    , sellerListDialog(nullptr)
    , dbManager(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Student & Seller Management (MDI + DB)");
    
    // Створити менеджер БД
    dbManager = new SqliteDBManager(this);
    
    // Створити немодальні вікна списків
    studentListDialog = new StudentListDialog(this);
    sellerListDialog = new SellerListDialog(this);
    
    // Передати БД в діалоги
    studentListDialog->setDatabase(dbManager->getDB());
    sellerListDialog->setDatabase(dbManager->getDB());
}

MainWindow::~MainWindow()
{
    delete studentListDialog;
    delete sellerListDialog;
    delete dbManager;
    delete ui;
}

void MainWindow::on_pushButton_createStudent_clicked()
{
    StudentDialog* dialog = new StudentDialog(this);
    connect(dialog, &StudentDialog::studentCreated, 
            this, &MainWindow::onStudentCreated);
    dialog->exec();
    delete dialog;
}

void MainWindow::on_pushButton_createSeller_clicked()
{
    SellerDialog* dialog = new SellerDialog(this);
    connect(dialog, &SellerDialog::sellerCreated, 
            this, &MainWindow::onSellerCreated);
    dialog->exec();
    delete dialog;
}

void MainWindow::on_pushButton_showStudents_clicked()
{
    if (studentListDialog->isVisible()) {
        studentListDialog->hide();
        ui->pushButton_showStudents->setText("Показати Students");
    } else {
        studentListDialog->updateList();
        studentListDialog->show();
        ui->pushButton_showStudents->setText("Сховати Students");
    }
}

void MainWindow::on_pushButton_showSellers_clicked()
{
    if (sellerListDialog->isVisible()) {
        sellerListDialog->hide();
        ui->pushButton_showSellers->setText("Показати Sellers");
    } else {
        sellerListDialog->updateList();
        sellerListDialog->show();
        ui->pushButton_showSellers->setText("Сховати Sellers");
    }
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::onStudentCreated(Student* student)
{
    // Зберегти в БД
    if (dbManager->insertIntoTable(*student)) {
        QMessageBox::information(this, "Успіх", "Student збережено в БД!");
        
        // Оновити вікно зі списком якщо воно відкрите
        if (studentListDialog->isVisible()) {
            studentListDialog->updateList();
        }
    } else {
        QMessageBox::warning(this, "Помилка", "Не вдалося зберегти Student в БД!");
    }
    
    // Видалити об'єкт
    delete student;
}

void MainWindow::onSellerCreated(Seller* seller)
{
    // Зберегти в БД
    if (dbManager->insertIntoTable(*seller)) {
        QMessageBox::information(this, "Успіх", "Seller збережено в БД!");
        
        // Оновити вікно зі списком якщо воно відкрите
        if (sellerListDialog->isVisible()) {
            sellerListDialog->updateList();
        }
    } else {
        QMessageBox::warning(this, "Помилка", "Не вдалося зберегти Seller в БД!");
    }
    
    // Видалити об'єкт
    delete seller;
}
