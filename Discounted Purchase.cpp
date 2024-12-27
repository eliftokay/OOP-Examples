#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
protected:
    string name;
    string id;

public:
    Person(string name, string id) {
        this->name = name;
        this->id = id;
    }

    // Common purchase method for all persons
    virtual void purchase(double amount) {
        cout << name << " purchased for " << amount << " units." << endl;
    }
};

class Employee : public Person {
public:
    Employee(string name, string id) : Person(name, id) {}

    void purchase(double amount) override {
        double discount = 0.15; // 15% discount for employees
        double discountedPrice = amount - (amount * discount);
        cout << name << " purchased for " << discountedPrice << " units after employee discount." << endl;
    }
};

class Customer : public Person {
public:
    Customer(string name, string id) : Person(name, id) {}

    // Regular purchase
    void purchase(double amount) override {
        cout << name << " purchased for " << amount << " units." << endl;
    }

    // Purchase with D&R card number
    void purchase(double amount, string dnrGiftCardNo) {
        if (!dnrGiftCardNo.empty()) {
            double discount = 0.10; // 10% discount for D&R card holders
            double discountedPrice = amount - (amount * discount);
            cout << name << " purchased for " << discountedPrice << " units after D&R card discount." << endl;
        }
        else {
            purchase(amount); // No D&R card, use regular purchase method
        }
    }
};

int main() {
    Person person("John Doe", "001");
    person.purchase(100);  // Regular purchase

    Employee employee("Jane Smith", "002");
    employee.purchase(100); // Purchase with employee discount

    Customer customer("Elif Tokay", "003");
    customer.purchase(100); // Regular purchase
    customer.purchase(100, "1234567890"); // Purchase with D&R card
    customer.purchase(100, ""); // Purchase without D&R card

    return 0;
}