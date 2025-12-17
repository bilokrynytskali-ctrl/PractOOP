#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include "Student.h"
#include "Seller.h"

class SqliteDBManager : public QObject
{
    Q_OBJECT

public:
    explicit SqliteDBManager(QObject *parent = nullptr);
    ~SqliteDBManager();

    void connectToDataBase();
    void closeDataBase();
    QSqlDatabase getDB();
    bool createTables();

    bool insertIntoTable(const Student& student);
    bool insertIntoTable(const Seller& seller);

    bool removeStudent(int id);
    bool removeSeller(int id);

private:
    QSqlDatabase db;
};

#endif // SQLITEDBMANAGER_H
