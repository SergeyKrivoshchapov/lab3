#pragma once
#include <string>
#include <stdexcept>

class Person {
private:
    std::string Name;
    double Weight;
public:
    Person(const std::string& name, double weight);

    std::string getName() const;
    double getWeight() const;

};