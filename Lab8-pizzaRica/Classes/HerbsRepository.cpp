#include "HerbsRepository.h"
#include <stdexcept>

HerbsRepository::HerbsRepository() {
    auto data = DataLoader::LoadFromFile("herbs.txt");
    data_ = std::move(data);
}

int HerbsRepository::GetAvailableQuantity(const std::string& ingredientType) const {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + ingredientType);
    }
    return std::stoi(it->second[0]);
}

void HerbsRepository::UpdateQuantity(const std::string& ingredientType, int newQuantity) {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + ingredientType);
    }
    it->second[0] = std::to_string(newQuantity);
    DataLoader::SaveToFile("herbs.txt", data_);
}
