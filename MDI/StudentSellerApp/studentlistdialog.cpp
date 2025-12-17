#include "studentlistdialog.h"
#include "ui_studentlistdialog.h"

StudentListDialog::StudentListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentListDialog)
{
    ui->setupUi(this);
    setWindowTitle("Список Students");
}

StudentListDialog::~StudentListDialog()
{
    delete ui;
}

void StudentListDialog::setStudents(const QVector<Student*>& students)
{
    updateList(students);
}

void StudentListDialog::updateList(const QVector<Student*>& students)
{
    ui->listWidget->clear();
    
    for (const auto& student : students) {
        QString info = QString("ID: %1 - %2")
                        .arg(student->getId())
                        .arg(QString::fromStdString(student->getFullName()));
        ui->listWidget->addItem(info);
    }
    
    ui->label_count->setText(QString("Всього: %1").arg(students.size()));
}
