#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <list>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Seller.h"
using namespace std;

// Прототипи функцій
void testLists();
int showMenu();
void addObjectToMap(map<int, Person*>& people);
void displayObjectById(const map<int, Person*>& people);
void displayAllObjects(const map<int, Person*>& people);

// Функція тестування списків
void testLists() {
    cout << "\n=== Testing std::list ===" << endl;

    // Генератор випадкових чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Перший список - непарні числа
    list<int> oddList;
    cout << "\nGenerating odd numbers..." << endl;
    while (oddList.size() < 10) {
        int num = dis(gen);
        if (num % 2 != 0) {  // Якщо непарне
            oddList.push_back(num);
        }
    }

    // Другий список - парні числа (з використанням ітератора)
    list<int> evenList;
    cout << "Generating even numbers..." << endl;
    while (evenList.size() < 10) {
        int num = dis(gen);
        if (num % 2 == 0) {  // Якщо парне
            auto it = evenList.end();
            evenList.insert(it, num);
        }
    }

    // Виведення перших двох списків
    cout << "\nOdd list (before sort): ";
    for (const auto& num : oddList) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Even list (before sort): ";
    for (const auto& num : evenList) {
        cout << num << " ";
    }
    cout << endl;

    // Сортування списків
    oddList.sort();
    evenList.sort();

    cout << "\nOdd list (after sort): ";
    for (const auto& num : oddList) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Even list (after sort): ";
    for (const auto& num : evenList) {
        cout << num << " ";
    }
    cout << endl;

    // Об'єднання списків
    list<int> mergedList;
    merge(oddList.begin(), oddList.end(),
          evenList.begin(), evenList.end(),
          back_inserter(mergedList));

    cout << "\nMerged list: ";
    for (const auto& num : mergedList) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Merged list size: " << mergedList.size() << endl;
}

// Функція виводу меню
int showMenu() {
    int choice;
    cout << "\n=== Menu ===" << endl;
    cout << "1. Add object to map" << endl;
    cout << "2. Display object by ID" << endl;
    cout << "3. Display all objects" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

// Функція додавання об'єкта в map
void addObjectToMap(map<int, Person*>& people) {
    int type, id;

    cout << "\n--- Add Object ---" << endl;
    cout << "Select type: 1 - Student, 2 - Seller: ";
    cin >> type;
    cin.ignore();

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    // Перевірка чи ID вже існує
    if (people.find(id) != people.end()) {
        cout << "Error: Object with ID " << id << " already exists!" << endl;
        return;
    }

    if (type == 1) {
        // Створення Student
        string lastName, firstName, patronymic, address, phone, faculty, group;
        int course;

        cout << "Enter last name: "; getline(cin, lastName);
        cout << "Enter first name: "; getline(cin, firstName);
        cout << "Enter patronymic: "; getline(cin, patronymic);
        cout << "Enter address: "; getline(cin, address);
        cout << "Enter phone: "; getline(cin, phone);
        cout << "Enter faculty: "; getline(cin, faculty);
        cout << "Enter course: "; cin >> course; cin.ignore();
        cout << "Enter group: "; getline(cin, group);

        Student* student = new Student(id, lastName, firstName, patronymic,
                                       address, phone, faculty, course, group);
        people[id] = student;
        cout << "\nStudent added successfully with ID: " << id << endl;

    } else if (type == 2) {
        // Створення Seller
        string lastName, firstName, patronymic, address, accountNumber;

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

        people[id] = seller;
        cout << "\nSeller added successfully with ID: " << id << endl;

    } else {
        cout << "Invalid type!" << endl;
    }
}

// Функція виведення об'єкта за ID
void displayObjectById(const map<int, Person*>& people) {
    int id;
    cout << "\n--- Display Object by ID ---" << endl;
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    auto it = people.find(id);
    if (it != people.end()) {
        cout << "\nFound object with ID " << id << ":" << endl;
        it->second->display();
    } else {
        cout << "Object with ID " << id << " not found!" << endl;
    }
}

// Функція виведення всіх об'єктів
void displayAllObjects(const map<int, Person*>& people) {
    cout << "\n--- All Objects in Map ---" << endl;

    if (people.empty()) {
        cout << "Map is empty!" << endl;
        return;
    }

    cout << "Total objects: " << people.size() << endl;

    for (const auto& pair : people) {
        cout << "\n>>> ID: " << pair.first << " <<<" << endl;
        pair.second->display();
    }
}

int main() {
    cout << "========================================" << endl;
    cout << "=== Practical Work #8: list & map ===" << endl;
    cout << "========================================\n" << endl;

    // Тестування std::list
    testLists();

    // Робота з std::map
    cout << "\n\n========================================" << endl;
    cout << "=== Working with std::map<int, Person*> ===" << endl;
    cout << "========================================\n" << endl;

    map<int, Person*> people;

    bool running = true;
    while (running) {
        int choice = showMenu();

        switch (choice) {
        case 1:
            addObjectToMap(people);
            break;
        case 2:
            displayObjectById(people);
            break;
        case 3:
            displayAllObjects(people);
            break;
        case 4:
            running = false;
            cout << "\nExiting program..." << endl;
            break;
        default:
            cout << "\nInvalid choice! Try again." << endl;
        }
    }

    // Очищення пам'яті
    cout << "\n--- Cleaning up memory ---" << endl;
    for (auto& pair : people) {
        delete pair.second;
    }
    people.clear();

    cout << "\nProgram finished successfully!" << endl;
    return 0;
}
