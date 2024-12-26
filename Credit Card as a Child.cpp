#include <iostream>
#include <string>

using namespace std;

class Card {
private:
    string cardNumber;
    string securityCode;
    string owner;

public:
    Card(string cardNumber, string securityCode, string owner) {
        this->cardNumber = cardNumber;
        this->securityCode = securityCode;
        this->owner = owner;
    }

    string getCardNumber() {
        return cardNumber;
    }

    string getSecurityCode() {
        return securityCode;
    }

    string getOwner() {
        return owner;
    }
};

class CreditCard : public Card {
private:
    int limit;

public:
    CreditCard(string cardNumber, string securityCode, string owner, int limit)
        : Card(cardNumber, securityCode, owner) {
        this->limit = limit;
    }

    int getLimit() {
        return limit;
    }
};

int main() {
    CreditCard myCard("1234 5678 9876 5432", "123", "Elif Tokay", 5000);
    cout << "Card Number: " << myCard.getCardNumber() << endl;
    cout << "Security Code: " << myCard.getSecurityCode() << endl;
    cout << "Owner: " << myCard.getOwner() << endl;
    cout << "Limit: " << myCard.getLimit() << endl;

    return 0;
}