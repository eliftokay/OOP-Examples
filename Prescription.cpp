#include <iostream>
#include <string>
using namespace std;

class Patient;

class Doctor {
public:
    Doctor() {

    }
    void writePrescription(const Patient& patient) {
        cout << "A prescription was written for " << patient.name << endl;
    }
};

class Patient {
private:
    string name;
    int age;

public:
    Patient(string name, int age) {
        this->age = age;
        this->name = name;
    }
    friend class Doctor;
};

int main() {
    Patient patient("Elif Tokay", 20);
    cout << patient.name; //To show that name is unaccesable, please comment out while debugging
    Doctor doctor;
    doctor.writePrescription(patient);
    return 0;
}
