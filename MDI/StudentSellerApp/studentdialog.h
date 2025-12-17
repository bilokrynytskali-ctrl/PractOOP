#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include "Student.h"

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();

signals:
    void studentCreated(Student* student);

private slots:
    void on_pushButton_create_clicked();

private:
    Ui::StudentDialog *ui;
};

#endif // STUDENTDIALOG_H
