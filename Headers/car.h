// car.h
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

// Concrete class representing a Car
class Car : public Vehicle {
    int airbags;
    bool isElectric;

public:
    Car(const std::string &make, const std::string &model, int year, int airbags, bool isElectric = false);
    ~Car();
    Car(const Car& other);
    Car& operator=(const Car& other);

    std::string getInfo() const override;

    void display() const override;
    void performDiagnostics() const override;
};

#endif // CAR_H

