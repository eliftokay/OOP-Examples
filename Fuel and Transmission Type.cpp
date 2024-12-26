#include <iostream>
#include <string>
using namespace std;

enum FuelType {
    DIESEL,
    GASOLINE,
    LPG,
    ELECTRIC
};

enum TransmissionType {
    AUTOMATIC,
    MANUAL,
    SEMI_AUTOMATIC
};

class Car {
private:
    string brand;
    FuelType fuelType;
    TransmissionType transmissionType;

public:
    Car(string brand, FuelType fuelType, TransmissionType transmissionType) {
        this->brand = brand;
        this->fuelType = fuelType;
        this->transmissionType = transmissionType;
    }

    string getBrand() {
        return brand;
    }

    FuelType getFuelType() {
        return fuelType;
    }

    TransmissionType getTransmissionType() {
        return transmissionType;
    }

    string getFuelTypeDescription() {
        switch (fuelType) {
        case DIESEL:
            return "Diesel";
        case GASOLINE:
            return "Gasoline";
        case LPG:
            return "LPG";
        case ELECTRIC:
            return "Electric";
        default:
            return "Unknown";
        }
    }

    string getTransmissionTypeDescription() {
        switch (transmissionType) {
        case AUTOMATIC:
            return "Automatic";
        case MANUAL:
            return "Manual";
        case SEMI_AUTOMATIC:
            return "Semi-Automatic";
        default:
            return "Unknown";
        }
    }
};

int main() {
    Car car("Toyota", DIESEL, AUTOMATIC);

    cout << "Car Brand: " << car.getBrand() << endl;
    cout << "Fuel Type: " << car.getFuelTypeDescription() << endl;
    cout << "Transmission Type: " << car.getTransmissionTypeDescription() << endl;

    return 0;
}