#include <iostream>
#include <string>

using namespace std;

class Teacher {
public:
    static const int facultyCode = 50; // Constant faculty code for all teachers
    string name;
    string assistant;
    string* lectures; // Pointer to dynamically allocate an array for lectures
    int lectureCount; // To keep track of the number of lectures

    // Default constructor
    Teacher() : name(""), assistant(""), lectureCount(0) {
        cout << "Default Teacher constructor called" << endl;
        lectures = new string[3]; // Allocate memory for lectures array
    }

    // Constructor with name only
    Teacher(string name) : name(name), assistant(""), lectureCount(3) {
        cout << "Teacher with name constructor called" << endl;
        lectures = new string[3]; // Allocate memory for lectures array
        lectures[0] = "Introduction to Programming";
        lectures[1] = "Object Oriented Programming";
        lectures[2] = "Data Structures and Algorithms"; // Initializing lectures list
    }

    // Constructor with name and assistant
    Teacher(string name, string assistant) : name(name), assistant(assistant), lectureCount(3) {
        cout << "Teacher with assistant constructor called" << endl;
        lectures = new string[3]; // Allocate memory for lectures array
        lectures[0] = "Introduction to Programming";
        lectures[1] = "Object Oriented Programming";
        lectures[2] = "Data Structures and Algorithms"; // Initializing lectures list
    }

    // Method to assign an assistant
    void assignAssistant(string newAssistant) { // Taking string by value
        assistant = newAssistant;
    }

    // Method to add a lecture
    void addLecture(string lecture) { // Taking string by value
        if (lectureCount < 3) { // Check if there's room for a new lecture
            lectures[lectureCount] = lecture;
            lectureCount++;
        }
        else {
            cout << "No more lectures can be added." << endl;
        }
    }

    // Display method
    void display() const {
        cout << "Teacher Name: " << name << endl;
        cout << "Faculty Code: " << facultyCode << endl;
        if (!assistant.empty()) {
            cout << "Assistant: " << assistant << endl;
        }
        else {
            cout << "No assistant assigned." << endl;
        }
        cout << "Lectures: ";
        if (lectureCount == 0) {
            cout << "No lectures assigned." << endl;
        }
        else {
            for (int i = 0; i < lectureCount; i++) {
                cout << lectures[i] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Teacher() {
        cout << "New teacher needed." << endl; // Message when destructor is called
        delete[] lectures; // Free the dynamically allocated memory
    }
};

int main() {
    // Default constructor
    Teacher t1; // t1 remains empty
    t1.display();

    // Constructor with name only
    Teacher t2("Ayþegül Tüysüz Erman");
    t2.display();

    // Constructor with name and assistant for t3
    Teacher t3("Bora Çalýþkan", "Elif Tokay"); // t3 with assistant "Elif Tokay"
    t3.display();

    // Assign assistant to t2
    t2.assignAssistant("Bora Çalýþkan");
    t2.display();

    // Demonstrating the destructor call (implicitly called when objects go out of scope)
    return 0;
}