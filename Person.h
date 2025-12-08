#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;
class Person {
protected:
int id;

string lastName;
string firstName;
string patronymic;
string address;
public:
Person();
Person(int id, string lastName, string firstName, string patronymic, string address);
Person(const Person& other);
virtual ~Person();
virtual void display() const;
void setId(int id);
void setLastName(const string& lastName);
void setFirstName(const string& firstName);
void setPatronymic(const string& patronymic);
void setAddress(const string& address);
int getId() const;
 string getLastName() const;
string getFirstName() const;
string getPatronymic() const;
string getAddress() const;
string getFullName() const;
};
#endif
