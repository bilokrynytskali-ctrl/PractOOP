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

    // ЧИСТО ВІРТУАЛЬНИЙ метод (робить клас абстрактним)
    virtual void display() const = 0;

    // Звичайний метод для базової інформації
    void displayBase() const;

    // Геттери
    int getId() const;
    string getFullName() const;
    string getLastName() const;
    string getFirstName() const;
    string getPatronymic() const;
    string getAddress() const;
};

#endif
