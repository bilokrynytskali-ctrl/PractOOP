#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Student.h"
#include "Seller.h"
#include "studentlistdialog.h"
#include "sellerlistdialog.h"
#include "sqlitedbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_createStudent_clicked();
    void on_pushButton_createSeller_clicked();
    void on_pushButton_showStudents_clicked();
    void on_pushButton_showSellers_clicked();
    void on_pushButton_exit_clicked();
    
    void onStudentCreated(Student* student);
    void onSellerCreated(Seller* seller);

private:
    Ui::MainWindow *ui;
    StudentListDialog* studentListDialog;
    SellerListDialog* sellerListDialog;
    SqliteDBManager* dbManager;
};

#endif // MAINWINDOW_H
