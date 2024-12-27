#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string nationality;

    Person(string name, string nationality) {
        this->name = name;
        this->nationality = nationality;
    }
};

class Team {
protected:
    string captain;
    string coach;

public:
    Team(string captain, string coach) {
        this->captain = captain;
        this->coach = coach;
    }

    virtual void assignCaptain(Person person) {
        this->captain = person.name;
        cout << "Captain assigned: " << person.name << endl;
    }

    string getCaptain() {
        return captain;
    }
};

class NationalTeam : public Team {
private:
    string country;

public:
    NationalTeam(string captain, string coach, string country) : Team(captain, coach) {
        this->country = country;
    }

    void assignCaptain(Person person) override {
        if (person.nationality == country) {
            this->captain = person.name;
            cout << "Captain assigned to national team: " << person.name << endl;
        }
        else {
            cout << "Error: Captain's nationality must match the team's country." << endl;
        }
    }
};

class ClubTeam : public Team {
private:
    int championshipCount;

public:
    ClubTeam(string captain, string coach, int championshipCount) : Team(captain, coach) {
        this->championshipCount = championshipCount;
    }

    int getChampionshipCount() {
        return championshipCount;
    }

    void setChampionshipCount(int count) {
        this->championshipCount = count;
    }
};

int main() {
    Person muslera("Fernando Muslera", "Uruguay");
    Person hakan("Hakan Çalhanoðlu", "Turkey");

    NationalTeam turkeyNationalTeam("", "Vincenzo Montella", "Turkey");
    ClubTeam galatasaray("", "Okan Buruk", 23);

    galatasaray.assignCaptain(muslera);
    cout << "Galatasaray's captain: " << galatasaray.getCaptain() << endl;

    turkeyNationalTeam.assignCaptain(muslera);
    turkeyNationalTeam.assignCaptain(hakan);
    cout << "Turkey's national team's captain: " << turkeyNationalTeam.getCaptain() << endl;

    return 0;
}