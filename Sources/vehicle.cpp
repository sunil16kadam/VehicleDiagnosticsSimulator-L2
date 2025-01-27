// vehicle.cpp
#include "../Headers/vehicle.h"

Vehicle::Vehicle(std::string make, std::string model, int year)
    : make(std::move(make)), model(std::move(model)), year(year) {}

Vehicle::~Vehicle() {
    std::cout << "Vehicle Destructor called for " << make << " " << model << "\n";
}

Vehicle::Vehicle(const Vehicle& other) : make(other.make), model(other.model), year(other.year) {}

std::string Vehicle::getInfo() const {
    return make + ", " + model + ", " + std::to_string(year);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        make = other.make;
        model = other.model;
        year = other.year;
    }
    return *this;
}

////
