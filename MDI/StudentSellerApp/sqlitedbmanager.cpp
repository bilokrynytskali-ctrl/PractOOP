#include "sqlitedbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

SqliteDBManager::SqliteDBManager(QObject *parent)
    : QObject(parent)
{
    connectToDataBase();
}

SqliteDBManager::~SqliteDBManager()
{
    closeDataBase();
}

void SqliteDBManager::connectToDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("StudentSellerDB.db");
    
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";
        createTables();
    }
}

void SqliteDBManager::closeDataBase()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database closed";
    }
}

QSqlDatabase SqliteDBManager::getDB()
{
    return db;
}

bool SqliteDBManager::createTables()
{
    QSqlQuery query(db);
    
    // Таблиця для Students
    QString createStudentsTable = 
        "CREATE TABLE IF NOT EXISTS Students ("
        "id INTEGER PRIMARY KEY, "
        "lastName TEXT NOT NULL, "
        "firstName TEXT NOT NULL, "
        "patronymic TEXT NOT NULL, "
        "address TEXT NOT NULL, "
        "phone TEXT NOT NULL, "
        "faculty TEXT NOT NULL, "
        "course INTEGER NOT NULL, "
        "groupName TEXT NOT NULL"
        ");";
    
    if (!query.exec(createStudentsTable)) {
        qDebug() << "Error creating Students table:" << query.lastError().text();
        return false;
    }
    
    // Таблиця для Sellers
    QString createSellersTable = 
        "CREATE TABLE IF NOT EXISTS Sellers ("
        "id INTEGER PRIMARY KEY, "
        "lastName TEXT NOT NULL, "
        "firstName TEXT NOT NULL, "
        "patronymic TEXT NOT NULL, "
        "address TEXT NOT NULL, "
        "accountNumber TEXT NOT NULL"
        ");";
    
    if (!query.exec(createSellersTable)) {
        qDebug() << "Error creating Sellers table:" << query.lastError().text();
        return false;
    }
    
    // Таблиця для товарів продавців
    QString createProductsTable = 
        "CREATE TABLE IF NOT EXISTS Products ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "seller_id INTEGER NOT NULL, "
        "productName TEXT NOT NULL, "
        "FOREIGN KEY (seller_id) REFERENCES Sellers(id) ON DELETE CASCADE"
        ");";
    
    if (!query.exec(createProductsTable)) {
        qDebug() << "Error creating Products table:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "All tables created successfully!";
    return true;
}

bool SqliteDBManager::insertIntoTable(const Student& student)
{
    QSqlQuery query(db);
    
    query.prepare("INSERT OR REPLACE INTO Students (id, lastName, firstName, patronymic, "
                  "address, phone, faculty, course, groupName) "
                  "VALUES (:id, :lastName, :firstName, :patronymic, "
                  ":address, :phone, :faculty, :course, :groupName)");
    
    query.bindValue(":id", student.getId());
    query.bindValue(":lastName", QString::fromStdString(student.getLastName()));
    query.bindValue(":firstName", QString::fromStdString(student.getFirstName()));
    query.bindValue(":patronymic", QString::fromStdString(student.getPatronymic()));
    query.bindValue(":address", QString::fromStdString(student.getAddress()));
    query.bindValue(":phone", QString::fromStdString(student.getPhone()));
    query.bindValue(":faculty", QString::fromStdString(student.getFaculty()));
    query.bindValue(":course", student.getCourse());
    query.bindValue(":groupName", QString::fromStdString(student.getGroup()));
    
    if (!query.exec()) {
        qDebug() << "Error inserting Student:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "Student inserted successfully!";
    return true;
}

bool SqliteDBManager::insertIntoTable(const Seller& seller)
{
    QSqlQuery query(db);
    
    query.prepare("INSERT OR REPLACE INTO Sellers (id, lastName, firstName, patronymic, "
                  "address, accountNumber) "
                  "VALUES (:id, :lastName, :firstName, :patronymic, "
                  ":address, :accountNumber)");
    
    query.bindValue(":id", seller.getId());
    query.bindValue(":lastName", QString::fromStdString(seller.getLastName()));
    query.bindValue(":firstName", QString::fromStdString(seller.getFirstName()));
    query.bindValue(":patronymic", QString::fromStdString(seller.getPatronymic()));
    query.bindValue(":address", QString::fromStdString(seller.getAddress()));
    query.bindValue(":accountNumber", QString::fromStdString(seller.getAccountNumber()));
    
    if (!query.exec()) {
        qDebug() << "Error inserting Seller:" << query.lastError().text();
        return false;
    }
    
    // Видалити старі товари цього продавця
    query.prepare("DELETE FROM Products WHERE seller_id = :seller_id");
    query.bindValue(":seller_id", seller.getId());
    query.exec();
    
    // Додати товари
    vector<string> products = seller.getProducts();
    for (const auto& product : products) {
        query.prepare("INSERT INTO Products (seller_id, productName) VALUES (:seller_id, :productName)");
        query.bindValue(":seller_id", seller.getId());
        query.bindValue(":productName", QString::fromStdString(product));
        
        if (!query.exec()) {
            qDebug() << "Error inserting product:" << query.lastError().text();
        }
    }
    
    qDebug() << "Seller and products inserted successfully!";
    return true;
}

bool SqliteDBManager::removeStudent(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Students WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error removing Student:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool SqliteDBManager::removeSeller(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Sellers WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error removing Seller:" << query.lastError().text();
        return false;
    }
    
    return true;
}
