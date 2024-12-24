#include <iostream>
#include <string>
using namespace std;

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

class TrafficLightController {
private:
    TrafficLight currentLight;

public:
    TrafficLightController(TrafficLight currentLight) {
        this->currentLight = currentLight;
    }

    TrafficLight getCurrentLight() {
        return currentLight;
    }

    void setCurrentLight(TrafficLight newLight) {
        this->currentLight = newLight;
    }

    string getLightDescription() {
        switch (currentLight) {
        case RED:
            return "Stop";
        case YELLOW:
            return "Caution";
        case GREEN:
            return "Go";
        default:
            return "Unknown";
        }
    }
};

int main() {
    TrafficLightController controller(RED);

    cout << "Current Light: " << controller.getLightDescription() << endl;

    controller.setCurrentLight(GREEN);
    cout << "Changed Light: " << controller.getLightDescription() << endl;

    return 0;
}