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
Student();
Student(string n, int a, double g);
Student(const Student& other);
~Student();
void display() const;
friend istream& operator>>(istream& in, Student& student);
friend ostream& operator<<(ostream& out, const Student& student);

};
#endif
