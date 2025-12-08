#include "Seller.h"
#include <algorithm>
Seller::Seller() {
id = 0;
lastName = "Unknown";
firstName = "Unknown";
patronymic = "Unknown";
address = "Unknown";
accountNumber = "0000000000";
 cout << "Default Seller constructor called" << endl;
}
Seller::Seller(int id, string lastName, string firstName, string patronymic,
string address, string accountNumber) {
this->id = id;
this->lastName = lastName;
this->firstName = firstName;
this->patronymic = patronymic;
this->address = address;
this->accountNumber = accountNumber;
cout << "Parameterized Seller constructor called for " << firstName << endl;
}
Seller::Seller(const Seller& other) {
id = other.id;
lastName = other.lastName;
firstName = other.firstName;
patronymic = other.patronymic;
address = other.address;
accountNumber = other.accountNumber;
products = other.products;
cout << "Copy Seller constructor called for " << firstName << endl;
}
Seller::~Seller() {
cout << "Seller destructor called for " << firstName << endl;
}
void Seller::addProduct(const string& product) {
products.push_back(product);
cout << "Product '" << product << "' added" << endl;
}
void Seller::removeProduct(const string& product) {
auto it = find(products.begin(), products.end(), product);
 if (it != products.end()) {
products.erase(it);
cout << "Product '" << product << "' removed" << endl;

} else {
cout << "Product '" << product << "' not found" << endl;
}
}
void Seller::displayProducts() const {
 cout << "Products list:" << endl;
if (products.empty()) {
 cout << "  No products" << endl;
} else 
{
for (size_t i = 0; i < products.size(); i++) {
cout << "  " << (i + 1) << ". " << products[i] << endl;
}
}
}
void Seller::display() const {
cout <<"\n=== Seller Information ===" << endl;
cout << "ID: " << id << endl;
cout << "Full name: " << lastName << " " << firstName << " " << patronymic << endl;
cout << "Address: " << address << endl;
cout << "Account number: " << accountNumber << endl;
displayProducts();
}
void Seller::setId(int id) { this->id = id; }
void Seller::setLastName(const string& lastName) { this->lastName = lastName; }
void Seller::setFirstName(const string& firstName) { this->firstName = firstName; }

void Seller::setPatronymic(const string& patronymic) { this->patronymic = patronymic; }

void Seller::setAddress(const string& address) { this->address = address; }

void Seller::setAccountNumber(const string& accountNumber) { this->accountNumber = accountNumber; }

int Seller::getId() const { return id; }

string Seller::getLastName() const { return lastName; }

string Seller::getFirstName() const { return firstName; }

string Seller::getPatronymic() const { return patronymic; }

string Seller::getAddress() const { return address; }

string Seller::getAccountNumber() const { return accountNumber; }

vector<string> Seller::getProducts() const { return products; }

