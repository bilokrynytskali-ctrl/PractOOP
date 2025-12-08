#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    // Конструктори
    Student();
    Student(string n, int a, double g);
    Student(const Student& other);

    // Деструктор
    ~Student();

    // Метод виведення
    void display() const;

    // Оператор порівняння
    bool operator==(const Student& other) const;

    // Дружні функції для операторів >> та
    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);
};

#endif
