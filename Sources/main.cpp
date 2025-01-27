/////////////////////////////////////////////////////////////////////////////////////
// Vehicle Diagnostics Simulator
// Filename: main.cpp
// Author: Sunil Kadam
// Last modified on 26 Jan 2025
/////////////////////////////////////////////////////////////////////////////////////

#include "../Headers/car.h"
#include "../Headers/truck.h"
#include "../Headers/diagnostics_manager.h"
#include "../Headers/file_manager.h"

int main() {
    DiagnosticsManager manager("vehicles.txt", "diagnostics.txt");

    // std::make_unique<Car> returns a std::unique_ptr<Car>, 
    // but since it is passed to addVehicle(), 
    // the actual type depends on the parameter type of the function addVehicle()
    // which is std::make_unique<vehicle>
    // This is necessary for polymorphic behavior
    manager.addVehicle(std::make_unique<Car>(std::string("Toyota"), std::string("Corolla"), 2020, 6, false));
    manager.addVehicle(std::make_unique<Car>(std::string("Tesla"), std::string("Model S"), 2022, 4, true));
    manager.addVehicle(std::make_unique<Truck>(std::string("Volvo"), std::string("FH16"), 2019, 20.0, 4));

    manager.saveVehicles();

    manager.performDiagnostics();

    return 0;
}

