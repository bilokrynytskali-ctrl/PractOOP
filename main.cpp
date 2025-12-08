#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Seller.h"
using namespace std;

int showMenu() {
    int choice;
    cout << "\n=== Menu ===" << endl;
    cout << "1. Create Student" << endl;
    cout << "2. Create Seller" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    cin.ignore();
    return choice;
}

Student* createStudent() {
    int id, course;
    string lastName, firstName, patronymic, address, phone, faculty, group;

    cout << "\n--- Creating Student ---" << endl;
    cout << "Enter ID: "; cin >> id; cin.ignore();
    cout << "Enter last name: "; getline(cin, lastName);
    cout << "Enter first name: "; getline(cin, firstName);
    cout << "Enter patronymic: "; getline(cin, patronymic);
    cout << "Enter address: "; getline(cin, address);
    cout << "Enter phone: "; getline(cin, phone);
    cout << "Enter faculty: "; getline(cin, faculty);
    cout << "Enter course: "; cin >> course; cin.ignore();
    cout << "Enter group: "; getline(cin, group);

    return new Student(id, lastName, firstName, patronymic, address,
                       phone, faculty, course, group);
}

Seller* createSeller() {
    int id;
    string lastName, firstName, patronymic, address, accountNumber;

    cout << "\n--- Creating Seller ---" << endl;
    cout << "Enter ID: "; cin >> id; cin.ignore();
    cout << "Enter last name: "; getline(cin, lastName);
    cout << "Enter first name: "; getline(cin, firstName);
    cout << "Enter patronymic: "; getline(cin, patronymic);
    cout << "Enter address: "; getline(cin, address);
    cout << "Enter account number: "; getline(cin, accountNumber);

    Seller* seller = new Seller(id, lastName, firstName, patronymic,
                                address, accountNumber);

    int productCount;
    cout << "How many products to add? "; cin >> productCount; cin.ignore();
    for (int i = 0; i < productCount; i++) {
        string product;
        cout << "Enter product " << (i+1) << ": ";
        getline(cin, product);
        seller->addProduct(product);
    }

    return seller;
}

int main() {
    cout << "=== Practical Work #5: Polymorphism ===" << endl;

    Person* people[5];

    for (int i = 0; i < 5; i++) {
        cout << "\n--- Object " << (i+1) << " of 5 ---" << endl;
        int choice = showMenu();

        if (choice == 1) {
            people[i] = createStudent();
        } else if (choice == 2) {
            people[i] = createSeller();
        } else {
            cout << "Invalid choice! Creating default Student..." << endl;
            people[i] = new Student();
        }
    }

    cout << "\n\n========================================" << endl;
    cout << "=== Displaying all created objects ===" << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\n--- Object " << (i+1) << " ---" << endl;
        people[i]->display();
    }

    cout << "\n\n========================================" << endl;
    cout << "=== Testing polymorphism (virtual method) ===" << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nCalling display() for object " << (i+1) << ":" << endl;
        people[i]->display();
    }

    cout << "\n\n=== Cleaning up memory ===" << endl;
    for (int i = 0; i < 5; i++) {
        delete people[i];
    }

    cout << "\nProgram finished successfully!" << endl;
    return 0;
}
