#include <iostream>
#include "Vector.h"
#include "Person.h"
#include "Student.h"
#include "Seller.h"
using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "   PRACTICAL WORK #6: Template Vector  " << endl;
    cout << "========================================" << endl << endl;

    // ============================================
    // ЧАСТИНА 1: Тестування Vector з базовими типами
    // ============================================
    
    // Тест 1: Vector з int
    cout << "=== Test 1: Vector<int> ===" << endl;
    Vector<int> intVector;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);
    intVector.print();
    cout << "Element at index 1: " << intVector.at(1) << endl;
    cout << "Element [2]: " << intVector[2] << endl;
    intVector.pop_back();
    cout << "After pop_back(): ";
    intVector.print();
    cout << "Size: " << intVector.getSize() << ", Capacity: " << intVector.getCapacity() << endl;
    cout << endl;

    // Тест 2: Vector з double
    cout << "=== Test 2: Vector<double> ===" << endl;
    Vector<double> doubleVector;
    doubleVector.push_back(3.14159);
    doubleVector.push_back(2.71828);
    doubleVector.push_back(1.41421);
    doubleVector.print();
    cout << endl;

    // Тест 3: Vector з float (перевірка автоматичного розширення)
    cout << "=== Test 3: Vector<float> - Auto resize ===" << endl;
    Vector<float> floatVector;
    cout << "Adding 12 elements (initial capacity is 10)..." << endl;
    for (int i = 0; i < 12; i++) {
        floatVector.push_back(i * 1.5f);
    }
    floatVector.print();
    cout << endl;

    // Тест 4: Vector з long
    cout << "=== Test 4: Vector<long> ===" << endl;
    Vector<long> longVector;
    longVector.push_back(1000000L);
    longVector.push_back(2000000L);
    longVector.push_back(3000000L);
    longVector.print();
    cout << "Size: " << longVector.getSize() << endl;
    cout << "Capacity: " << longVector.getCapacity() << endl;
    cout << endl;

    // ============================================
    // ЧАСТИНА 2: Тестування Vector з вказівниками на базовий клас Person
    // ============================================
    
    cout << "========================================" << endl;
    cout << "=== Test 5: Vector<Person*> - Polymorphism ===" << endl;
    cout << "========================================" << endl << endl;
    
    Vector<Person*> personVector;
    
    // Створюємо об'єкти Student
    cout << "Creating Student objects..." << endl;
    Student* s1 = new Student(101, "Ivanov", "Ivan", "Ivanovich", 
                              "Kyiv, Shevchenko St. 10", "+380501234567",
                              "Computer Science", 2, "CS-21");
    
    Student* s2 = new Student(102, "Petrova", "Maria", "Petrovna",
                              "Kyiv, Khreshchatyk St. 25", "+380502345678",
                              "Mathematics", 3, "M-31");
    
    // Створюємо об'єкти Seller
    cout << "Creating Seller objects..." << endl;
    Seller* seller1 = new Seller(201, "Kovalenko", "Oleh", "Mykolayovych",
                                 "Kyiv, Maydan Nezalezhnosti 1", "ACC123456");
    seller1->addProduct("Laptop");
    seller1->addProduct("Mouse");
    seller1->addProduct("Keyboard");
    
    Seller* seller2 = new Seller(202, "Shevchenko", "Oksana", "Ivanivna",
                                 "Lviv, Svobody Ave. 5", "ACC789012");
    seller2->addProduct("Phone");
    seller2->addProduct("Tablet");
    
    // Додаємо об'єкти у Vector
    cout << "\nAdding objects to Vector<Person*>..." << endl;
    personVector.push_back(s1);
    personVector.push_back(s2);
    personVector.push_back(seller1);
    personVector.push_back(seller2);
    
    cout << "Vector size: " << personVector.getSize() << endl;
    cout << "Vector capacity: " << personVector.getCapacity() << endl;
    cout << endl;
    
    // ============================================
    // ЧАСТИНА 3: Виклик віртуального методу display()
    // ============================================
    
    cout << "========================================" << endl;
    cout << "=== Calling virtual method display() ===" << endl;
    cout << "========================================" << endl << endl;
    
    for (int i = 0; i < personVector.getSize(); i++) {
        cout << "--- Object " << (i + 1) << " ---" << endl;
        personVector[i]->display();  // Поліморфний виклик
        cout << endl;
    }
    
    // ============================================
    // ЧАСТИНА 4: Очищення пам'яті
    // ============================================
    
    cout << "========================================" << endl;
    cout << "=== Cleaning up memory ===" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < personVector.getSize(); i++) {
        delete personVector[i];
    }
    
    cout << "\n========================================" << endl;
    cout << "   All tests completed successfully!   " << endl;
    cout << "========================================" << endl;

    return 0;
}