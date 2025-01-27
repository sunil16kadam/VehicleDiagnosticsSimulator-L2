// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

// Abstract base class representing a generic vehicle
class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;
    float engineTemperature;

public:
    Vehicle(std::string make, std::string model, int year);
    virtual ~Vehicle();
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);

    virtual std::string getInfo() const; // Function to get vehicle info as a string

    virtual void display() const = 0; // Pure virtual function to display vehicle details
    virtual void performDiagnostics() const = 0; // Pure virtual function for diagnostics
};

#endif // VEHICLE_H

