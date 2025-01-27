// diagnostics_manager.cpp
#include "../Headers/diagnostics_manager.h"

DiagnosticsManager::DiagnosticsManager(std::string vehiclesFile, std::string diagnosticsFile)
        : vehiclesFile(std::move(vehiclesFile)), diagnosticsFile(std::move(diagnosticsFile)) {}

DiagnosticsManager::~DiagnosticsManager() {
    std::cout << "DiagnosticsManager Destructor called\n";
}

void DiagnosticsManager::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(std::move(vehicle));
    //Instead of saving to file everytinme we add vehicle,
    // we can only add to vector which is a local temporary storage
    // and store to file at the end of program or at some appropriate place.
}

void DiagnosticsManager::performDiagnostics() const {
    std::vector<std::string> diagnosticsData;
    for (const auto& vehicle : vehicles) {
        vehicle->performDiagnostics();
        diagnosticsData.push_back(vehicle->serialize()); // Assuming diagnostics data is part of serialization
    }
    FileManager::saveToFile(diagnosticsFile, diagnosticsData);
}

void DiagnosticsManager::saveVehicles() const {
    std::vector<std::string> data;
    for (const auto& vehicle : vehicles) {
        data.push_back(vehicle->serialize());
    }
    FileManager::saveToFile(vehiclesFile, data);
}
