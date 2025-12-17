#ifndef STUDENTLISTDIALOG_H
#define STUDENTLISTDIALOG_H

#include <QDialog>
#include <QVector>
#include "Student.h"

namespace Ui {
class StudentListDialog;
}

class StudentListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentListDialog(QWidget *parent = nullptr);
    ~StudentListDialog();
    
    void setStudents(const QVector<Student*>& students);
    void updateList(const QVector<Student*>& students);

private:
    Ui::StudentListDialog *ui;
};

#endif // STUDENTLISTDIALOG_H
