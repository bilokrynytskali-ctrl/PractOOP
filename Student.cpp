#include "Student.h"

#include <iostream>
#include <iostream>

using namespace std;
Student::Student() {
 name = "Unknown";
age = 0;
gpa = 0.0;
cout << "Default constructor called" << endl;
}
Student::Student(string n, int a, double g) {
name = n;
age = a;
gpa = g;
cout << "Parameterized constructor called for " << name << endl;
}
Student::Student(const Student& other) {
 name = other.name;
age = other.age;
gpa = other.gpa;
cout << "Copy constructor called for " << name << endl;
}
Student::~Student() {
cout << "Destructor called for " << name << endl;
}
void Student::display() const {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "GPA: " << gpa << endl;
}
istream& operator>>(istream& in, Student& student) {
cout << "Enter name: ";
getline(in, student.name);
cout << "Enter age: ";
in >> student.age;
cout << "Enter GPA: ";
in >> student.gpa;
in.ignore();
return in;
}
