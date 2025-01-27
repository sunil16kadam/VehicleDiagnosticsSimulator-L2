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
};
#endif // FILE_MANAGER_H


