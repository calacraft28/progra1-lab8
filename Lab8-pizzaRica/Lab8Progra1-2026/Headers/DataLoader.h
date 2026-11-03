#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class DataLoader {
public:
    // Loads "topping -> ingredients" (WITHOUT base ingredients) from a file.
    static std::unordered_map<std::string, std::vector<std::string>>
    LoadFromFile(const std::string& path);

    static void SaveToFile(
        const std::string& path,
        const std::unordered_map<std::string, std::vector<std::string>>& data);
};