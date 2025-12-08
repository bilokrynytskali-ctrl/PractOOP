#include <iostream>
#include "Seller.h"
using namespace std;

int main() {
    cout << "=== Testing Seller class ===" << endl << endl;

    // Створення продавця
    Seller seller1(1, "Коваленко", "Олег", "Петрович",
                   "вул. Хрещатик, 10", "UA123456789");

    // Додавання товарів
    seller1.addProduct("Ноутбук");
    seller1.addProduct("Телефон");
    seller1.addProduct("Планшет");

    // Виведення інформації
    seller1.display();

    cout << "\n--- Removing product ---" << endl;
    seller1.removeProduct("Телефон");

    seller1.display();

    cout << "\n=== Testing copy constructor ===" << endl;
    Seller seller2 = seller1;
    seller2.display();

    return 0;
}

