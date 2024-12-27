#include <iostream>
#include <string>

using namespace std;

class Flower {
protected:
    string color;
    double price;
    static string careAdvice;

public:
    Flower(string color, double price) {
        this->color = color;
        this->price = price;
    }

    virtual string getCareAdvice() {
        return "Water regularly and place in a sunny spot.";
    }

    virtual string toString() {
        return "Flower[color=" + color + ", price=" + to_string(price) + "]";
    }

    static string getCareAdviceStatic() {
        return careAdvice;
    }
};

string Flower::careAdvice = "Water regularly and place in a sunny spot.";

class Rose : public Flower {
public:
    Rose(string color, double price) : Flower(color, price) {}

    string getCareAdvice() override {
        return "Roses need plenty of sunlight and water, prune them regularly.";
    }
};

class Tulip : public Flower {
public:
    Tulip(string color, double price) : Flower(color, price) {}

    string getCareAdvice() override {
        return "Tulips prefer cooler temperatures and need moderate watering.";
    }
};

class FlowerShop {
public:
    void sendFlower(Flower* flower) {
        cout << "Sending " << flower->toString() << " with care advice: "
            << flower->getCareAdvice() << endl;
    }

    void sendFlower(Flower* flower, string message) {
        cout << "Sending " << flower->toString() << " with care advice: "
            << flower->getCareAdvice() << endl;
        cout << "Personalized message: " << message << endl;
    }
};

int main() {
    FlowerShop shop;

    Flower* rose = new Rose("Red", 15.50);
    Flower* tulip = new Tulip("Yellow", 10.00);

    shop.sendFlower(rose);
    shop.sendFlower(tulip, "Happy Birthday!");

    delete rose;
    delete tulip;

    return 0;
}