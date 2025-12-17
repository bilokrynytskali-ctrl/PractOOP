#ifndef STUDENTLISTDIALOG_H
#define STUDENTLISTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class StudentListDialog;
}

class StudentListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentListDialog(QWidget *parent = nullptr);
    ~StudentListDialog();
    
    void setDatabase(QSqlDatabase db);
    void updateList();

private:
    Ui::StudentListDialog *ui;
    QSqlTableModel* model;
};

#endif // STUDENTLISTDIALOG_H
