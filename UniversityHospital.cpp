#include <iostream>
#include <string>

using namespace std;

class Hospital {
protected:
    string chiefDoctor;

public:
    Hospital(string chiefDoctor) {
        this->chiefDoctor = chiefDoctor;
    }

    string getChiefDoctor() {
        return chiefDoctor;
    }
};

class Faculty {
protected:
    string dean;

public:
    Faculty(string dean) {
        this->dean = dean;
    }

    string getDean() {
        return dean;
    }
};

class UniversityHospital : public Hospital, public Faculty {
private:
    string name;

public:
    UniversityHospital(string name, string chiefDoctor, string dean)
        : Hospital(chiefDoctor), Faculty(dean) {
        this->name = name;
    }

    void displayInfo() {
        cout << "University Hospital Name: " << name << endl;
        cout << "Chief Doctor: " << getChiefDoctor() << endl;
        cout << "Dean: " << getDean() << endl;
    }
};

int main() {
    UniversityHospital uh("MediHealth University Hospital", "Dr. Alice Green", "Prof. John Smith");
    uh.displayInfo();

    return 0;
}