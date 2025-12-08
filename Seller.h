#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Seller {
private:
int id;
string lastName;
 string firstName;
string patronymic;
string address;
string accountNumber;
vector<string> products;
public:
Seller();
Seller(int id, string lastName, string firstName, string patronymic,

string address, string accountNumber);
Seller(const Seller& other);
~Seller();
void addProduct(const string& product);
void removeProduct(const string& product);
void displayProducts() const;
void display() const;
void setId(int id);
void setLastName(const string& lastName);
void setFirstName(const string& firstName);

 void setPatronymic(const string& patronymic);
void setAddress(const string& address);
void setAccountNumber(const string& accountNumber);
 int getId() const;
string getLastName() const;
 string getFirstName() const;
string getPatronymic() const;
string getAddress() const;
string getAccountNumber() const;

vector<string> getProducts() const;
};
#endif
