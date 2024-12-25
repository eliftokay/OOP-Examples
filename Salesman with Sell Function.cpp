#include <iostream>

using namespace std;

class Product {
public:
    float price;
    Product(float p) {
        price = p;
    }
};

class Customer {
public:
    float balance;
    Customer(float b) {
        balance = b;
    }
};

class Salesman {
public:
    bool sell(Product& product, Customer& customer) {
        if (customer.balance >= product.price) {
            customer.balance -= product.price;
            return true;
        }
        return false;
    }
};

int main() {
    Product product(100.0);
    Customer customer(150.0);
    Salesman salesman;

    bool success = salesman.sell(product, customer);
    cout << (success ? "Sale successful!" : "Insufficient balance!") << endl;

    return 0;
}