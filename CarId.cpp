#include "CarId.h"

#include <algorithm>

std::unordered_set<std::string> CarId::car_ids;

bool CarId::IsDigit(const std::string &id) {
    return !id.empty() && std::all_of(id.begin(), id.end(), [](char c) {return std::isdigit(static_cast<unsigned char>(c));});
}


bool CarId::IsValidId(const std::string& id) { return car_ids.find(id) == car_ids.end(); }

void CarId::ClaimId(const std::string &id) {
    if (!IsValidId(id)) { throw std::invalid_argument("Id already exists"); }
    car_ids.insert(id);
}

void CarId::UnclaimId(const std::string &id) { car_ids.erase(id); }
