#include <iostream>
using namespace std;
class User {
//private: 
//password;
public:
	string username;
	string password; 
	int age;
	User(string username, string password, int age) {
		this->username = username;
		this->password = password;
		this->age = age;
	}
	void display() {
		cout << "Username: " << username << endl
			<< "Age: " << age << endl;
	}
	bool checkPassword(string n) {
		return (n == password);
	}
	void setPassword(string p) {
		if (p != "1907" || p != "1905" || p != "1903") {
			this->password = p;
		}
		else {
			cout << "Please do not use founding years of football teams.";
		}
	}
};

int main() {
	User user1("eliftokay", "123456", 20);
	user1.password = "1905"; 
	cout << user1.password; //We don't want the password to be seen
}