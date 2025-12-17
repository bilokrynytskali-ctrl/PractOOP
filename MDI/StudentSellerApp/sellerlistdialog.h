#ifndef SELLERLISTDIALOG_H
#define SELLERLISTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class SellerListDialog;
}

class SellerListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SellerListDialog(QWidget *parent = nullptr);
    ~SellerListDialog();
    
    void setDatabase(QSqlDatabase db);
    void updateList();

private:
    Ui::SellerListDialog *ui;
    QSqlTableModel* model;
};

#endif // SELLERLISTDIALOG_H
