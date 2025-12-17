#include "Student.h"

// Конструктор за замовчуванням
Student::Student() : Person() {
    phone = "000-000-0000";
    faculty = "Unknown";
    course = 1;
    group = "Unknown";
    cout << "Default Student constructor called" << endl;
}

// Параметризований конструктор
Student::Student(int id, string lastName, string firstName, string patronymic,
                 string address, string phone, string faculty, int course, string group)
    : Person(id, lastName, firstName, patronymic, address) {
    this->phone = phone;
    this->faculty = faculty;
    this->course = course;
    this->group = group;
    cout << "Parameterized Student constructor called" << endl;
}

// Конструктор копіювання
Student::Student(const Student& other) : Person(other) {
    phone = other.phone;
    faculty = other.faculty;
    course = other.course;
    group = other.group;
    cout << "Copy Student constructor called" << endl;
}

// Деструктор
Student::~Student() {
    cout << "Student destructor called" << endl;
}

// Реалізація чисто віртуального методу
void Student::display() const {
    cout << "\n=== Student Information ===" << endl;
    displayBase();
    cout << "Phone: " << phone << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Course: " << course << endl;
    cout << "Group: " << group << endl;
}

// Геттери
string Student::getPhone() const { return phone; }

string Student::getFaculty() const { return faculty; }

int Student::getCourse() const { return course; }

string Student::getGroup() const { return group; }
