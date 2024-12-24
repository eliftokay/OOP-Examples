#include <iostream>
#include <string>

using namespace std;

class App {
protected:
    string appName;
    bool notificationPermission;

public:
    App(const string& name) {
        this->appName = name;
        this->notificationPermission = true;
    }

    void turnOffNotifications() {
        if (this->notificationPermission) {
            this->notificationPermission = false;
            cout << this->appName << ": Notifications turned off." << endl;
        }
        else {
            cout << this->appName << ": Notifications are already off." << endl;
        }
    }
};

class SystemApp : public App {
public:
    SystemApp(const string& name) : App(name) {}

    void turnOffNotifications() {
        cout << this->appName << ": Notifications cannot be turned off for this application!" << endl;
    }
};

int main() {
    App* whatsapp = new App("WhatsApp");
    App* alarm = new SystemApp("Alarm");

    whatsapp->turnOffNotifications();
    whatsapp->turnOffNotifications();
    alarm->turnOffNotifications();

    delete whatsapp;
    delete alarm;

    return 0;
}