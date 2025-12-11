#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* array;           // Вказівник на динамічний масив
    int size;           // Кількість елементів
    int capacity;       // Поточний розмір масиву

public:
    // Конструктор
    Vector() {
        capacity = 10;
        size = 0;
        array = new T[capacity];
        cout << "Vector created with capacity: " << capacity << endl;
    }

    // Деструктор
    ~Vector() {
        delete[] array;
        cout << "Vector destroyed" << endl;
    }

    // Отримати кількість елементів
    int getSize() const {
        return size;
    }

    // Отримати ємність
    int getCapacity() const {
        return capacity;
    }

    // Додати елемент в кінець
    void push_back(T element) {
        if (size >= capacity) {
            // Збільшуємо capacity вдвічі
            capacity *= 2;
            T* newArray = new T[capacity];
            
            // Копіюємо старі елементи
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            
            delete[] array;
            array = newArray;
            cout << "Capacity increased to: " << capacity << endl;
        }
        
        array[size] = element;
        size++;
    }

    // Видалити останній елемент
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    // Отримати елемент за індексом (з перевіркою)
    T at(int index) const {
        if (index >= 0 && index < size) {
            return array[index];
        }
        throw out_of_range("Index out of range");
    }

    // Перевантаження оператора []
    T& operator[](int index) {
        return array[index];
    }

    // Константна версія operator[]
    const T& operator[](int index) const {
        return array[index];
    }

    // Метод для виведення всіх елементів
    void print() const {
        cout << "Vector [size=" << size << ", capacity=" << capacity << "]: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

#endif