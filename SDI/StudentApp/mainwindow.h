#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_create_clicked();
    void on_actionCreate_triggered();
    void on_actionDisplay_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Student* student;
};

#endif // MAINWINDOW_H
