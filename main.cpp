#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    cout << "=== Testing overloaded operators ===" << endl << endl;

    Student object1, object2, object3;

    cout << "Enter data for 3 students:" << endl;
    cin >> object1 >> object2 >> object3;

    cout << "\n=== Displaying students ===" << endl;
    cout << object1 << endl << object2 << endl << object3;

    cout << "\n=== Testing operator == ===" << endl;
    if (object1 == object2) {
        cout << "object1 and object2 are EQUAL" << endl;
    } else {
        cout << "object1 and object2 are NOT equal" << endl;
    }

    if (object1 == object3) {
        cout << "object1 and object3 are EQUAL" << endl;
    } else {
        cout << "object1 and object3 are NOT equal" << endl;
    }

    return 0;
}

