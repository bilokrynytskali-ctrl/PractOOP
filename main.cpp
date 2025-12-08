#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Seller.h"
using namespace std;

int main() {
    cout << "=== Testing inheritance: Person -> Student, Seller ===" << endl << endl;

    // Testing Student
    cout << "--- Creating Students ---" << endl;
    Student student1(101, "Ivanenko", "Ivan", "Ivanovych",
                     "Shevchenko st., 15", "067-123-4567",
                     "Information Technologies", 2, "IT-21");

    Student student2(102, "Petrenko", "Maria", "Petrivna",
                     "Franko st., 8", "095-987-6543",
                     "Economics", 3, "EK-31");

    student1.display();
    student2.display();

    // Testing Seller
    cout << "\n\n--- Creating Sellers ---" << endl;
    Seller seller1(201, "Kovalenko", "Oleg", "Petrovych",
                   "Khreshchatyk st., 10", "UA123456789");
    seller1.addProduct("Laptop");
    seller1.addProduct("Phone");
    seller1.addProduct("Tablet");

    Seller seller2(202, "Sydorenko", "Olga", "Mykolaivna",
                   "Nezalezhnosti ave., 25", "UA987654321");
    seller2.addProduct("Monitor");
    seller2.addProduct("Keyboard");

    seller1.display();
    seller2.display();

    cout << "\n\n--- Testing polymorphism ---" << endl;
    Person* people[4];
    people[0] = &student1;
    people[1] = &student2;
    people[2] = &seller1;
    people[3] = &seller2;

    for (int i = 0; i < 4; i++) {
        cout << "\nPerson #" << (i + 1) << ": " << people[i]->getFullName() << endl;
    }

    return 0;
}
