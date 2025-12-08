#include "Person.h"

// Конструктор за замовчуванням
Person::Person() {
    id = 0;
    lastName = "Unknown";
    firstName = "Unknown";
    patronymic = "Unknown";
    address = "Unknown";
    cout << "Default Person constructor called" << endl;
}

// Параметризований конструктор
Person::Person(int id, string lastName, string firstName, string patronymic, string address) {
    this->id = id;
    this->lastName = lastName;
    this->firstName = firstName;
    this->patronymic = patronymic;
    this->address = address;
    cout << "Parameterized Person constructor called" << endl;
}

// Конструктор копіювання
Person::Person(const Person& other) {
    id = other.id;
    lastName = other.lastName;
    firstName = other.firstName;
    patronymic = other.patronymic;
    address = other.address;
    cout << "Copy Person constructor called" << endl;
}

// Деструктор
Person::~Person() {
    cout << "Person destructor called" << endl;
}

// Виведення інформації
void Person::display() const {
    cout << "ID: " << id << endl;
    cout << "Full name: " << lastName << " " << firstName << " " << patronymic << endl;
    cout << "Address: " << address << endl;
}

int Person::getId() const { return id; }

string Person::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}
