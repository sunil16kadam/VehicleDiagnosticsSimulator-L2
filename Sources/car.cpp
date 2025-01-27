// car.cpp
#include "../Headers/car.h"

// Car::Car(std::string make, std::string model, int year, int airbags, bool isElectric)
//     : Vehicle(std::move(make), std::move(model), year), airbags(airbags), isElectric(isElectric) {
//     std::cout << "Car created: " << make << ", " << model << ", " << std::endl;
// }
// std::move(make) and std::move(model) cast the local variables make and model to rvalues. 
// When passed to the base class Vehicle, the move constructor transfer ownership.
// Hence, the local variables make and model in the derived class ctor become empty or invalid.
// Prefer passing strings by reference to avoid unnecessary moves.

Car::Car(const std::string &make, const std::string &model, int year, int airbags, bool isElect)
    : Vehicle(std::move(make), std::move(model), year), airbags(airbags), isElectric(isElect) {}

Car::~Car() {
    std::cout << "Car Destructor called for " << make << " " << model << "\n";
}

Car::Car(const Car& other) : Vehicle(other), airbags(other.airbags) {}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        airbags = other.airbags;
        engineTemperature = other.engineTemperature;
    }
    return *this;
}

std::string Car::getInfo() const {
    return Vehicle::getInfo() + ", Airbags: " + std::to_string(airbags);
}

void Car::display() const {
    std::cout << "Car: " << make << " " << model << " (" << year << ")\n"
              << "Airbags: " << airbags << ", Engine Temp: " << engineTemperature << "\n";
}

void Car::performDiagnostics() const {
    std::cout << "Performing diagnostics for Car: " << make << " " << model << "\n";
}
