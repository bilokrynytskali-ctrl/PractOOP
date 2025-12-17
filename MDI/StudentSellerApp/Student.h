#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    string phone;
    string faculty;
    int course;
    string group;

public:
    // Конструктори
    Student();
    Student(int id, string lastName, string firstName, string patronymic,
            string address, string phone, string faculty, int course, string group);
    Student(const Student& other);

    // Деструктор
    ~Student();

    // Перевизначений метод виведення
    void display() const override;
    
    // Геттери
    string getPhone() const;
    string getFaculty() const;
    int getCourse() const;
    string getGroup() const;
};

#endif
