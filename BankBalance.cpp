#include <iostream>
using namespace std;

class BankAccount {
public:
    double balance;
    BankAccount(double initialBalance) : balance(initialBalance) {}
    void increaseBalance(int amount) {
        balance += amount;
    }
};

int main() {
    BankAccount account(1000.0);
    cout << "Balance before increasing: " << account.balance;
    account.balance += 100000; //Increasing the balance without permission
    cout << "Balace after increasing: " << account.balance << endl;
    return 0;
}