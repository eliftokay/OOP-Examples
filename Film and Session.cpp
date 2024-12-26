#include <iostream>
#include <string>

using namespace std;

class Film {
private:
    string title;

public:
    // Film constructor
    Film(const string& filmTitle) : title(filmTitle) {}

    // Returns the title of the film
    string getTitle() const {
        return title;
    }
};

class Session {
private:
    int startHour;
    int endHour;
    int endMinute;

public:
    // Session constructor
    Session(int start, int end, int endMin) : startHour(start), endHour(end), endMinute(endMin) {
        cout << "Session object created." << endl;
    }

    // Starts playing the film
    void showFilm(const Film& film) {
        cout << "Session started. Enjoy your film: " << film.getTitle() << endl;
    }

    // Displays session hours
    void displayHours() const {
        cout << "Film showtime: " << startHour << ":00 - " << endHour << ":" << (endMinute < 10 ? "0" : "") << endMinute << endl;
    }

    // Destructor
    ~Session() {
        cout << "Session destructor called, session ended." << endl;
    }
};

int main() {
    // Creating Film and Session objects
    Film film("Inception");
    Session* session = new Session(18, 19, 30);

    // Start playing the film
    session->showFilm(film);
    session->displayHours();

    // Delete the Session object
    delete session;

    // session->displayHours(); // One might try this to see session object no longer exists

    return 0;
}