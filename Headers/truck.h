// truck.h
#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

// Concrete class representing a Truck
class Truck : public Vehicle {
    float cargoCapacity;
    int axleCount;

public:
    Truck(const std::string &make, const std::string &model, int year, float cargoCapacity, int axleCount);
    ~Truck();
    Truck(const Truck& other);
    Truck& operator=(const Truck& other);

    std::string serialize() const override {
            return Vehicle::serialize() + "," + std::to_string(cargoCapacity) + "," + std::to_string(axleCount);
    }

    void display() const override;
    void performDiagnostics() const override;
};

#endif // TRUCK_H