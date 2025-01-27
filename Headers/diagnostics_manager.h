// diagnostics_manager.h
#ifndef DIAGNOSTICS_MANAGER_H
#define DIAGNOSTICS_MANAGER_H

#include "vehicle.h"
#include "file_manager.h"
#include <vector>
#include <memory>
#include <string>

// Class to manage multiple vehicles and diagnostics
class DiagnosticsManager {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    FileManager fileManager;
    std::string filePath;

public:
    // DiagnosticsManager() = default;
    DiagnosticsManager(const std::string& file);
    ~DiagnosticsManager();
    DiagnosticsManager(const DiagnosticsManager& other) = delete;
    DiagnosticsManager& operator=(const DiagnosticsManager& other) = delete;

    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void performDiagnostics() const;

    void loadFromFile();
    void saveToFile();
};

#endif // DIAGNOSTICS_MANAGER_H

