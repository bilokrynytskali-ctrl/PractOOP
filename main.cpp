#include <iostream>

#include "Seller.h"
using namespace std;
int main() {
cout << "=== Testing Seller class ===" << endl << endl;
Seller seller1(1, "Коваленко", "Олег", "Петрович",
"вул. Хрещатик, 10", "UA123456789");
seller1.addProduct("Ноутбук");
seller1.addProduct("Телефон");
 seller1.addProduct("Планшет");
seller1.display();
cout << "\n--- Removing product ---" << endl;
seller1.removeProduct("Телефон");
seller1.display();
cout << "\n=== Testing copy constructor ===" << endl;
Seller seller2 = seller1;
seller2.display();
return 0;
}
