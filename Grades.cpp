#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    char letterGrade;
    double percentageGrade;

public:
    Student() {
        this->letterGrade = 'F';
        this->percentageGrade = 0.0;
    }

    Student(char letterGrade, double percentageGrade) {
        this->letterGrade = letterGrade;
        this->percentageGrade = percentageGrade;
    }

    void setGrade(char grade) {
        this->letterGrade = grade;
    }

    void setGrade(double grade) {
        this->percentageGrade = grade;
    }

    void displayGrades() {
        cout << "Letter Grade: " << letterGrade << endl;
        cout << "Percentage Grade: " << percentageGrade << endl;
    }
};

int main() {
    Student student1;
    student1.setGrade('A');
    student1.setGrade(95.5);
    student1.displayGrades();

    Student student2('B', 85.3);
    student2.displayGrades();

    return 0;
}