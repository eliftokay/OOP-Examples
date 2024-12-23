/*
This is an example of an aggregation since the Student class has a weak association with the Computer class, 
as the computer can be assigned or removed without affecting the existence of the student.

However, when this course was taught, the concept of aggregation had not yet been covered, 
so this example was explained through the concept of passing another class as a parameter only.
*/

#include <iostream>
using namespace std;

class Computer {
public:
    int ramAmount;
    string brandName;
    int memorySize; 
    int usedMemory;    
    int availableMemory; 

    Computer(int ramAmount, string brandName, int memorySize, int usedMemory) {
        this->ramAmount = ramAmount;
        this->brandName = brandName;
        this->memorySize = memorySize;
        this->usedMemory = usedMemory;
        availableMemory = memorySize - usedMemory;
    }

    void displayInfo() {
        cout << "Brand Name: " << brandName << ", Memory Size: " << memorySize << endl;
        cout << "Used Memory: " << usedMemory << ", Available Memory: " << availableMemory << endl;
    }
};

class Student {
public:
    string name;
    string facultyName = "BBTF";
    int age;
    bool gender; //will be used as true for women and false for men
    Computer* userComputer;

    Student() : userComputer(nullptr) {} // Initialize userComputer to nullptr

    Student(string name, int age, bool gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        userComputer = nullptr; // Initialize to nullptr
    }

    Student(string name, int age, bool gender, Computer* userComputer) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->userComputer = userComputer;
    }

    string getName() {
        return this->name;
    }

    // A method to display student information
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
        if (userComputer != nullptr) {
            cout << "Computer info: " << endl;
            userComputer->displayInfo();
        }
        else {
            cout << "No computer assigned." << endl;
        }
    }
};

int main() {
    Computer monster(32, "Monster", 1000, 45);
    Student elif("Elif", 20, 1, &monster);
    elif.displayInfo();

    return 0;
}