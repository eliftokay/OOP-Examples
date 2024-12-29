/*
Examine the code below. Make an assumption about the output and run the code to check.

A) Parent constructor is called.

B) Child constructor is called.

C) Parent constructor is called.
   Child constructor is called.

D) Child constructor is called.
   Parent constructor is called.
*/

#include <iostream>
using namespace std;

class Parent {
public:
	int value = 3;
	Parent() {
		cout << "Parent constructor is called." << endl;
	}
};

class Child : public Parent {
public:
	Child() : Parent () {
		cout << "Child constructor is called." << endl;
	}
};

int main() {
	Child child;
}