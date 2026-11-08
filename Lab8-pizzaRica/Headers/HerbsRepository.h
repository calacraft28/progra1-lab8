#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class HerbsRepository {
public:
    HerbsRepository();

    int GetAvailableQuantity(const std::string& ingredientType) const;
    void UpdateQuantity(const std::string& ingredientType, int newQuantity);

private:
    mutable std::unordered_map<std::string, std::vector<std::string>> data_;
};
