#include <iostream>
using namespace std;

class Ticket {
private:
    string date;
    string name;
    int price;
    int discount;

public:
    Ticket(string date, string name, int price) {
        this->date = date;
        this->name = name;
        this->price = price;
        this->discount = 0;
    }

    Ticket(string date, string name, int price, int discount) {
        this->date = date;
        this->name = name;
        this->price = price;
        this->discount = discount;
    }

    int getFinalPrice() {
        return price - discount;
    }

    void displayTicketInfo() {
        cout << "Date: " << date << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Discount: $" << discount << endl;
        cout << "Final Price: $" << getFinalPrice() << endl;
    }
};

int main() {
    Ticket ticket1("2024-12-25", "Concert", 100);
    ticket1.displayTicketInfo();

    cout << endl;

    Ticket ticket2("2024-12-25", "Concert", 100, 20);
    ticket2.displayTicketInfo();

    return 0;
}