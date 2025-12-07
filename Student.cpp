#include "Student.h"
#include <iostream>
using namespace std;
void Student::display() const {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "GPA: " << gpa << endl;
}
