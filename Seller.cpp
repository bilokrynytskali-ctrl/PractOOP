#include "Seller.h"
#include <algorithm>

// Конструктор за замовчуванням
Seller::Seller() : Person() {
    accountNumber = "0000000000";
    cout << "Default Seller constructor called" << endl;
}

// Параметризований конструктор
Seller::Seller(int id, string lastName, string firstName, string patronymic,
               string address, string accountNumber)
    : Person(id, lastName, firstName, patronymic, address) {
    this->accountNumber = accountNumber;
    cout << "Parameterized Seller constructor called" << endl;
}

// Конструктор копіювання
Seller::Seller(const Seller& other) : Person(other) {
    accountNumber = other.accountNumber;
    products = other.products;
    cout << "Copy Seller constructor called" << endl;
}

// Деструктор
Seller::~Seller() {
    cout << "Seller destructor called" << endl;
}

// Додати товар
void Seller::addProduct(const string& product) {
    products.push_back(product);
    cout << "Product '" << product << "' added" << endl;
}

// Видалити товар
void Seller::removeProduct(const string& product) {
    auto it = find(products.begin(), products.end(), product);
    if (it != products.end()) {
        products.erase(it);
        cout << "Product '" << product << "' removed" << endl;
    } else {
        cout << "Product '" << product << "' not found" << endl;
    }
}

// Показати список товарів
void Seller::displayProducts() const {
    cout << "Products list:" << endl;
    if (products.empty()) {
        cout << "  No products" << endl;
    } else {
        for (size_t i = 0; i < products.size(); i++) {
            cout << "  " << (i + 1) << ". " << products[i] << endl;
        }
    }
}

// Виведення інформації
void Seller::display() const {
    cout << "\n=== Seller Information ===" << endl;
    Person::display();
    cout << "Account number: " << accountNumber << endl;
    displayProducts();
}
