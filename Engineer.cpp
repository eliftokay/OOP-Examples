#include <iostream>
#include <string>

using namespace std;

class Engineer {
protected:
    string name;
    int experience;

public:
    Engineer(string name, int experience) {
        this->name = name;
        this->experience = experience;
    }
    virtual void displayField() = 0;

    virtual ~Engineer() {}
};

class ComputerEngineer : public Engineer {
public:
    ComputerEngineer(string name, int experience) : Engineer(name, experience) {
        this->name = name;
        this->experience = experience;
    }

    void displayField() override {
        cout << "Computer Engineer: " << name << ", Experience: " << experience << " years" << endl;
    }
};

class MechanicalEngineer : public Engineer {
public:
    MechanicalEngineer(string name, int experience) : Engineer(name, experience) {
        this->name = name;
        this->experience = experience;
    }

    void displayField() override {
        cout << "Mechanical Engineer: " << name << ", Experience: " << experience << " years" << endl;
    }
};

class IndustrialEngineer : public Engineer {
public:
    IndustrialEngineer(string name, int experience) : Engineer(name, experience) {
        this->name = name;
        this->experience = experience;
    }

    void displayField() override {
        cout << "Industrial Engineer: " << name << ", Experience: " << experience << " years" << endl;
    }
};

int main() {
    ComputerEngineer compEng("Alice", 5);
    MechanicalEngineer mechEng("Bob", 10);

    compEng.displayField();
    mechEng.displayField();

    /*
    Engineer* Charlie;
    Charlie->displayField();
    Charlie = new IndustrialEngineer("Charlie", 7);
    Charlie->displayField();

    delete Charlie;
    */

    return 0;
}