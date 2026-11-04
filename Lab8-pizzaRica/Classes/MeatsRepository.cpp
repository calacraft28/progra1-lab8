#include "MeatsRepository.h"
#include <stdexcept>


MeatsRepository::MeatsRepository() {
	auto data = DataLoader::LoadFromFile("meats.txt");
	data_ = std::move(data);
}

int MeatsRepository::GetAvailableQuantity(const std::string& ingredientType) const {
	auto it = data_.find(ingredientType);
	if (it == data_.end()) {
		throw std::invalid_argument("Tipo de carne desconocido: " + ingredientType);
	}
	return std::stoi(it->second[0]);
}

void MeatsRepository::UpdateQuantity(const std::string& ingredientType, int newQuantity) {
	auto it = data_.find(ingredientType);
	if (it == data_.end()) {
		throw std::invalid_argument("Tipo de carne desconocido: " + ingredientType);
	}
	it->second[0] = std::to_string(newQuantity);
	DataLoader::SaveToFile("meats.txt", data_);
}
