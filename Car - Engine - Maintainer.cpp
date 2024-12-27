/*
In this example, the relationship between car and engine is a composition.
Engine is created whenever a car is created, and destroyed with the car it's attached to.

The relationship between car and maintainer is an aggregation, since maintainer can exist without the car.
This independency is shown by adding the same maintainer to another car.

Both Constructors and Destructors of each object has informing messages to show the relationship
and the lifetimes of objects.
*/

#include <iostream>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine created" << endl;
    }
    ~Engine() {
        cout << "Engine destroyed" << endl;
    }
    void start() {
        cout << "Engine started" << endl;
    }
};

class Maintainer {
public:
    string name;

    Maintainer(string name) : name(name) {
        cout << "Maintainer " << name << " created" << endl;
    }
    ~Maintainer() {
        cout << "Maintainer " << name << " destroyed" << endl;
    }

    void performMaintenance() {
        cout << "Maintenance performed by " << name << endl;
    }
};

class Car {
private:
    Engine engine;
    Maintainer& maintainer;

public:
    Car(Maintainer& maintainer) : maintainer(maintainer) {
        cout << "Car created" << endl;
    }
    ~Car() {
        cout << "Car destroyed" << endl;
    }

    void startCar() {
        engine.start();
        maintainer.performMaintenance();
    }
};

int main() {
    Maintainer carMaintainer("John");
    Car myCar(carMaintainer);
    myCar.startCar();

    cout << endl << "Creating another car with the same maintainer:" << endl;
    Car anotherCar(carMaintainer);
    anotherCar.startCar();

    return 0;
}