#ifndef SELLER_H
#define SELLER_H

#include "Person.h"
#include <vector>
#include <string>
using namespace std;

class Seller : public Person {
private:
    string accountNumber;
    vector<string> products;

public:
    // Конструктори
    Seller();
    Seller(int id, string lastName, string firstName, string patronymic,
           string address, string accountNumber);
    Seller(const Seller& other);

    // Деструктор
    ~Seller();

    // Методи для роботи зі списком товарів
    void addProduct(const string& product);
    void removeProduct(const string& product);
    void displayProducts() const;

    // Перевизначений метод виведення
    void display() const override;
};

#endif
