//Static

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name;
    int age;
    int id;
    static int nextId;

public:
    User(string name, int age) {
        this->name = name;
        this->age = age;
        this->id = nextId++;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

int User::nextId = 1;

int main() {
    User user1("Alice", 25);
    User user2("Bob", 30);
    User user3("Charlie", 22);

    user1.display();
    user2.display();
    user3.display();

    return 0;
}