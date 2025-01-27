// file_manager.cpp
#include "../Headers/file_manager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(const std::string& file) : filePath(file) {}

void FileManager::appendToFile(const std::string& data) {
    std::ofstream outFile(filePath, std::ios::app);
    if (outFile.is_open()) {
        outFile << data << std::endl;
    }
}

std::vector<std::string> FileManager::readFromFile() {
    std::vector<std::string> data;
    std::ifstream inFile(filePath);
    std::string line;
    while (std::getline(inFile, line)) {
        data.push_back(line);
    }
    return data;
}

void FileManager::saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    for (const auto& line : data) {
        file << line << std::endl;
    }
}

static std::vector<std::string> loadFromFile(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }
    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line);
    }
    return data;
}



