// truck.cpp
#include "../Headers/truck.h"

// Truck::Truck(std::string make, std::string model, int year, float cargoCapacity, int axleCount)
//     : Vehicle(std::move(make), std::move(model), year), cargoCapacity(cargoCapacity), axleCount(axleCount) {

// }
// std::move(make) and std::move(model) cast the local variables make and model to rvalues. 
// When passed to the base class Vehicle, the move constructor transfer ownership.
// Hence, the local variables make and model in the derived class ctor become empty or invalid.
// Prefer passing strings by reference to avoid unnecessary moves.

Truck::Truck(const std::string &make, const std::string &model, int year, float cargoCapacity, int axleCount)
    : Vehicle(std::move(make), std::move(model), year), cargoCapacity(cargoCapacity), axleCount(axleCount) {}

Truck::~Truck() {
    std::cout << "Truck Destructor called for " << make << " " << model << "\n";
}

Truck::Truck(const Truck& other) : Vehicle(other), cargoCapacity(other.cargoCapacity), axleCount(other.axleCount) {}

Truck& Truck::operator=(const Truck& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        cargoCapacity = other.cargoCapacity;
        axleCount = other.axleCount;
    }
    return *this;
}

void Truck::display() const {
    std::cout << "Truck: " << make << " " << model << " (" << year << ")\n"
              << "Cargo Capacity: " << cargoCapacity << " tons, Axle Count: " << axleCount << "\n";
}

void Truck::performDiagnostics() const {
    std::cout << "Performing diagnostics for Truck: " << make << " " << model << "\n";
}