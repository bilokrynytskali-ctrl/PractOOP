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
void display() const;
};
#endif
