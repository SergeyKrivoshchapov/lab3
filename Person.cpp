#include "Person.h"

Person::Person(const std::string& name, double weight) : Name(name), Weight(weight) {
    if (name.empty()) throw std::invalid_argument("Name cannot be empty");
    if (weight <= 1 || weight > 300) throw std::out_of_range("Weight cannot be unrealistic");
}

std::string Person::getName() const { return Name; }
double Person::getWeight() const { return Weight; }