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

// void FileManager::saveToFile(const std::string& filename, const std::string& data) {
//     std::ofstream outFile(filename);
//     if (!outFile) {
//         std::cerr << "Error opening file for writing." << std::endl;
//         return;
//     }
//     outFile << data;
//     std::cout << "Data saved to " << filename << " successfully." << std::endl;
// }

// void FileManager::readFromFile(const std::string& filename) {
//     std::ifstream inFile(filename);
//     if (!inFile) {
//         std::cerr << "Error opening file for reading." << std::endl;
//         return;
//     }
//     std::string line;
//     while (std::getline(inFile, line)) {
//         std::cout << line << std::endl;
//     }
// }

