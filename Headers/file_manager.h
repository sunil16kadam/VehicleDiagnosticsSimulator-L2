// file_manager.h
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

// Class to handle file operations
class FileManager {
    std::string filePath;

public:
    FileManager(const std::string& file);
    
    void appendToFile(const std::string& data);
    std::vector<std::string> readFromFile();

    static void saveToFile(const std::string& filename, const std::vector<std::string>& data);
    static std::vector<std::string> loadFromFile(const std::string& filename);
};
#endif // FILE_MANAGER_H


 