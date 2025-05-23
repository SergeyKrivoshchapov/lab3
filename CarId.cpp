#include "CarId.h"

std::unordered_set<std::string> CarId::car_ids;

bool CarId::IsValidId(const std::string& id) { return car_ids.find(id) == car_ids.end(); }

void CarId::ClaimId(const std::string &id) {
    if (!IsValidId(id)) { throw std::invalid_argument("Id already exists"); }
    car_ids.insert(id);
}

void CarId::UnclaimId(const std::string &id) { car_ids.erase(id); }
