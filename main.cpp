#include <iostream>
#include "Student.h"
using namespace std;
int main() {
cout << "=== Testing overloaded operator >> ===" << endl << endl;
Student object1, object2, object3;
 cout << "Enter data for 3 students:" << endl;
cin >> object1 >> object2 >> object3;
cout << "\n=== Students created successfully ===" << endl;
return 0;
}
