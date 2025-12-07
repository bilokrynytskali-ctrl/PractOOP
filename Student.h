#ifndef STUDENT_H
#define STUDENT_H
#include <string>
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
};
#endif
