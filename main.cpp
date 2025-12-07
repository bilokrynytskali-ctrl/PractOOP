#include <iostream>
#include "Student.h"
using namespace std;
int main() {
 cout << "=== Testing overloaded operators >> and << ===" << endl << endl;
Student object1, object2, object3;
cout << "Enter data for 3 students:" << endl;
cin >> object1 >> object2 >> object3;
cout << "\n=== Displaying students ===" << endl;
cout << object1 << endl << object2 << endl << object3;
return 0;
}
