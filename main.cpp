#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Person.h"
#include "Student.h"
#include "Seller.h"
using namespace std;

// Функція для виведення вектора чисел
void printVector(const string& name, const vector<int>& vec) {
    cout << name << ": ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Функція для виведення вектора вказівників на Person
void printPersonVector(const string& name, const vector<Person*>& vec) {
    cout << "\n=== " << name << " (size: " << vec.size() << ") ===" << endl;
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "\n[" << i << "] ";
        vec[i]->display();
    }
}

// Меню для створення об'єктів
int showMenu() {
    int choice;
    cout << "\n=== Add Object Menu ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add Seller" << endl;
    cout << "0. Finish adding" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

// Створення Student
Student* createStudent() {
    int id, course;
    string lastName, firstName, patronymic, address, phone, faculty, group;
    
    cout << "\n--- Creating Student ---" << endl;
    cout << "ID: "; cin >> id; cin.ignore();
    cout << "Last name: "; getline(cin, lastName);
    cout << "First name: "; getline(cin, firstName);
    cout << "Patronymic: "; getline(cin, patronymic);
    cout << "Address: "; getline(cin, address);
    cout << "Phone: "; getline(cin, phone);
    cout << "Faculty: "; getline(cin, faculty);
    cout << "Course: "; cin >> course; cin.ignore();
    cout << "Group: "; getline(cin, group);
    
    return new Student(id, lastName, firstName, patronymic, address, phone, faculty, course, group);
}

// Створення Seller
Seller* createSeller() {
    int id;
    string lastName, firstName, patronymic, address, accountNumber;
    
    cout << "\n--- Creating Seller ---" << endl;
    cout << "ID: "; cin >> id; cin.ignore();
    cout << "Last name: "; getline(cin, lastName);
    cout << "First name: "; getline(cin, firstName);
    cout << "Patronymic: "; getline(cin, patronymic);
    cout << "Address: "; getline(cin, address);
    cout << "Account number: "; getline(cin, accountNumber);
    
    Seller* seller = new Seller(id, lastName, firstName, patronymic, address, accountNumber);
    
    int productCount;
    cout << "Number of products: "; cin >> productCount; cin.ignore();
    for (int i = 0; i < productCount; i++) {
        string product;
        cout << "Product " << (i+1) << ": ";
        getline(cin, product);
        seller->addProduct(product);
    }
    
    return seller;
}

int main() {
    cout << "============================================" << endl;
    cout << "   PRACTICAL WORK #7: STL Algorithms       " << endl;
    cout << "============================================" << endl << endl;

    // ============================================
    // ЧАСТИНА 1: Робота з векторами цілих чисел
    // ============================================
    
    cout << "=== Part 1: Integer Vectors ===" << endl << endl;
    
    // Генератор випадкових чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> oddDist(1, 99);   // Непарні числа
    uniform_int_distribution<> evenDist(2, 100); // Парні числа
    
    // Вектор 1: Непарні числа (через індекс)
    vector<int> oddVector(10);
    cout << "Filling vector 1 with 10 odd numbers (using index)..." << endl;
    for (size_t i = 0; i < oddVector.size(); i++) {
        int num;
        do {
            num = oddDist(gen);
        } while (num % 2 == 0); // Переконуємось, що число непарне
        oddVector[i] = num;
    }
    
    // Вектор 2: Парні числа (через ітератор)
    vector<int> evenVector(10);
    cout << "Filling vector 2 with 10 even numbers (using iterator)..." << endl;
    for (auto it = evenVector.begin(); it != evenVector.end(); ++it) {
        int num;
        do {
            num = evenDist(gen);
        } while (num % 2 != 0); // Переконуємось, що число парне
        *it = num;
    }
    
    // Виведення векторів до сортування
    cout << "\nBefore sorting:" << endl;
    printVector("Odd vector", oddVector);
    printVector("Even vector", evenVector);
    
    // Сортування векторів
    sort(oddVector.begin(), oddVector.end());
    sort(evenVector.begin(), evenVector.end());
    
    cout << "\nAfter sorting:" << endl;
    printVector("Odd vector (sorted)", oddVector);
    printVector("Even vector (sorted)", evenVector);
    
    // Об'єднання векторів
    vector<int> mergedVector(oddVector.size() + evenVector.size());
    merge(oddVector.begin(), oddVector.end(), 
          evenVector.begin(), evenVector.end(), 
          mergedVector.begin());
    
    cout << "\nAfter merging:" << endl;
    printVector("Merged vector", mergedVector);
    
    // ============================================
    // ЧАСТИНА 2: Робота з векторами вказівників Person
    // ============================================
    
    cout << "\n\n============================================" << endl;
    cout << "=== Part 2: Person* Vectors ===" << endl;
    cout << "============================================" << endl;
    
    // Створення та заповнення вектора через меню
    vector<Person*> personVector;
    
    while (true) {
        int choice = showMenu();
        
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            personVector.push_back(createStudent());
            cout << "Student added successfully!" << endl;
        } else if (choice == 2) {
            personVector.push_back(createSeller());
            cout << "Seller added successfully!" << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    // Виведення початкового вектора
    printPersonVector("Original vector", personVector);
    
    // Створення копії вектора
    vector<Person*> personVectorCopy;
    for (Person* p : personVector) {
        // Створюємо копії об'єктів
        Student* student = dynamic_cast<Student*>(p);
        Seller* seller = dynamic_cast<Seller*>(p);
        
        if (student) {
            personVectorCopy.push_back(new Student(*student));
        } else if (seller) {
            personVectorCopy.push_back(new Seller(*seller));
        }
    }
    
    cout << "\n\n--- Removing Students from vector 1 ---" << endl;
    // Видалення всіх Student з першого вектора
    auto it1 = personVector.begin();
    while (it1 != personVector.end()) {
        if (dynamic_cast<Student*>(*it1)) {
            delete *it1;
            it1 = personVector.erase(it1);
        } else {
            ++it1;
        }
    }
    
    cout << "--- Removing Sellers from vector 2 ---" << endl;
    // Видалення всіх Seller з другого вектора
    auto it2 = personVectorCopy.begin();
    while (it2 != personVectorCopy.end()) {
        if (dynamic_cast<Seller*>(*it2)) {
            delete *it2;
            it2 = personVectorCopy.erase(it2);
        } else {
            ++it2;
        }
    }
    
    // Виведення результатів
    printPersonVector("Vector 1 (only Sellers)", personVector);
    printPersonVector("Vector 2 (only Students)", personVectorCopy);
    
    // Очищення пам'яті
    cout << "\n\n--- Cleaning up memory ---" << endl;
    for (Person* p : personVector) {
        delete p;
    }
    for (Person* p : personVectorCopy) {
        delete p;
    }
    
    cout << "\n============================================" << endl;
    cout << "   All tests completed successfully!       " << endl;
    cout << "============================================" << endl;

    return 0;
}