#include <iostream>
#include <fstream>
#include <string>

class light {
private:
    bool isOn;

public:
    light() : isOn(false) {}
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    std::string getStatus() const { return isOn ? "On" : "Off"; }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

class thermostat {
private:
    int temperature;

public:
    thermostat() : temperature(20) {}
    void setTemperature(int t) { temperature = t; }
    int getTemperature() const { return temperature; }
};

class securitySystem {
private:
    bool isArmed;
public:
    securitySystem() : isArmed(false) {}
    void arm() { isArmed = true; }
    void disarm() { isArmed = false; }
    std::string getStatus() const { return isArmed ? "Armed" : "Disarmed"; }
    bool getState() const { return isArmed; }
    void setState(bool state) { isArmed = state; }
};

class curtains {
private:
    bool isUp;
public:
    curtains() : isUp(false) {}
    void raise() { isUp = true; }
    void lower() { isUp = false; }
    std::string getStatus() const { return isUp ? "Raised" : "Lowered"; }
    bool getState() const { return isUp; }
    void setState(bool state) { isUp = state; }
};

class airConditioner {
private:
    bool isOn;
public:
    airConditioner() : isOn(false) {}
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    std::string getStatus() const { return isOn ? "On" : "Off"; }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

class smartHome {
private:
    light light;
    thermostat thermostat;
    securitySystem security;
    curtains curtains;
    airConditioner airConditioner;
    const std::string stateFile = "home_state.txt";
public:
    void controlLight(bool state) { light.setState(state); }
    void setTemperature(int temp) { thermostat.setTemperature(temp); }
    void controlSecurity(bool state) { security.setState(state); }
    void controlCurtains(bool state) { curtains.setState(state); }
    void controlAirConditioner(bool state) { airConditioner.setState(state); }
    void displayStatus() const {
        std::cout << "\nCurrent State:\n";
        std::cout << "Light: " << light.getStatus() << "\n";
        std::cout << "Temperature: " << thermostat.getTemperature() << "°C\n";
        std::cout << "Security System: " << security.getStatus() << "\n";
        std::cout << "Curtains: " << curtains.getStatus() << "\n";
        std::cout << "Air Conditioner: " << airConditioner.getStatus() << "\n";
    }
    void saveState() const {
        std::ofstream file(stateFile);
        file << light.getState() << "\n";
        file << thermostat.getTemperature() << "\n";
        file << security.getState() << "\n";
        file << curtains.getState() << "\n";
        file << airConditioner.getState() << "\n";
        file.close();
    }

    void loadState() {
        std::ifstream file(stateFile);
        if (file.is_open()) {
            int temp;
            bool b1, b2, b3, b4;
            file >> b1 >> temp >> b2 >> b3 >> b4;
            light.setState(b1);
            thermostat.setTemperature(temp);
            security.setState(b2);
            curtains.setState(b3);
            airConditioner.setState(b4);
            std::cout << "State loaded from file.\n";
        } else {
            std::cout << "No previous state file found. Using default settings.\n";
        }
    }
};

int main() {
    smartHome home;
    home.loadState();
    home.displayStatus();
    int choice;
    bool bul = true;
    while (bul) {
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Turn on light\n";
        std::cout << "2. Turn off light\n";
        std::cout << "3. Set temperature\n";
        std::cout << "4. Arm security system\n";
        std::cout << "5. Disarm security system\n";
        std::cout << "6. Raise curtains\n";
        std::cout << "7. Lower curtains\n";
        std::cout << "8. Turn on air conditioner\n";
        std::cout << "9. Turn off air conditioner\n";
        std::cout << "10. Exit\n";
        std::cout << "> ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                home.controlLight(true);
                break;
            case 2:
                home.controlLight(false);
                break;
            case 3: {
                int temp;
                std::cout << "Enter temperature: ";
                std::cin >> temp;
                home.setTemperature(temp);
                break;
            }
            case 4:
                home.controlSecurity(true);
                break;
            case 5:
                home.controlSecurity(false);
                break;
            case 6:
                home.controlCurtains(true);
                break;
            case 7:
                home.controlCurtains(false);
                break;
            case 8:
                home.controlAirConditioner(true);
                break;
            case 9:
                home.controlAirConditioner(false);
                break;
            case 10:
                bul = false;
                break;
            default:
                continue;
        }
        if (choice != 10) {
            home.displayStatus();
        }
    }
    home.saveState();
    std::cout << "State saved to home_state.txt. Exiting...\n";
    return 0;
}