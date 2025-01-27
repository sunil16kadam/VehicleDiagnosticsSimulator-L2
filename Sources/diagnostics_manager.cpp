// diagnostics_manager.cpp
#include "../Headers/diagnostics_manager.h"

DiagnosticsManager::DiagnosticsManager(const std::string& file) : filePath(file), fileManager(file) {
    loadFromFile();
}

DiagnosticsManager::~DiagnosticsManager() {
    std::cout << "DiagnosticsManager Destructor called\n";
}

void DiagnosticsManager::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
    //Instead of saving to file everytinme we add vehicle,
    // we can only add to vector which is a local temporary storage
    // and store to file at the end of program or at some appropriate place.
    saveToFile();
}

void DiagnosticsManager::performDiagnostics() const {
    for (const auto& vehicle : vehicles) {
        vehicle->performDiagnostics();
    }
}

void DiagnosticsManager::loadFromFile() {
    std::vector<std::string> data = fileManager.readFromFile();
    for (const auto& entry : data) {
        std::cout << "Loaded: " << entry << std::endl;
    }
}

void DiagnosticsManager::saveToFile() {
    for (const auto& vehicle : vehicles) {
        fileManager.appendToFile(vehicle->getInfo());
    }
}
