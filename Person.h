#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    int id;
    string lastName;
    string firstName;
    string patronymic;
    string address;

public:
    // Конструктори
    Person();
    Person(int id, string lastName, string firstName, string patronymic, string address);
    Person(const Person& other);

    // Віртуальний деструктор
    virtual ~Person();

    // Віртуальний метод виведення
    virtual void display() const;

    // Геттери
    int getId() const;
    string getFullName() const;
};

#endif
