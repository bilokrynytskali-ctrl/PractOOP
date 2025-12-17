#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentdialog.h"
#include "sellerdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , studentListDialog(nullptr)
    , sellerListDialog(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Student & Seller Management (MDI)");
    
    // Створити немодальні вікна списків
    studentListDialog = new StudentListDialog(this);
    sellerListDialog = new SellerListDialog(this);
}

MainWindow::~MainWindow()
{
    // Очистити пам'ять
    for (auto student : students) {
        delete student;
    }
    for (auto seller : sellers) {
        delete seller;
    }
    
    delete studentListDialog;
    delete sellerListDialog;
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
        studentListDialog->updateList(students);
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
        sellerListDialog->updateList(sellers);
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
    students.append(student);
    ui->label_status->setText(QString("Students: %1 | Sellers: %2")
                               .arg(students.size())
                               .arg(sellers.size()));
}

void MainWindow::onSellerCreated(Seller* seller)
{
    sellers.append(seller);
    ui->label_status->setText(QString("Students: %1 | Sellers: %2")
                               .arg(students.size())
                               .arg(sellers.size()));
}
