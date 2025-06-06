#include "Car.h"
#include <stdexcept>
#include <chrono>
#include <iostream>

Car::Car(std::string& brand, std::string& model, int production_year, std::string& fuel_type, double car_self_weight, double car_max_weight,
    int people_capacity, double power, double fuel_amount, double fuel_capacity, double fuel_consumption, std::string& id) :
    Brand(brand),
    Model(model),
    ProductionYear(production_year),
    FuelType(fuel_type),
    CarSelfWeight(car_self_weight),
    CarMaxWeight(car_max_weight),
    PeopleCapacity(people_capacity),
    Power(power),
    FuelCapacity(fuel_capacity),
    FuelAmount(fuel_amount),
    FuelConsumption(fuel_consumption)
{
    if (brand.empty()) throw std::invalid_argument("Brand cannot be empty");
    if (model.empty()) throw std::invalid_argument("Model cannot be empty");
    static auto current_year = std::chrono::year_month_day{floor<std::chrono::days>(std::chrono::system_clock::now())}.year();
    if (production_year > static_cast<int>(current_year) || production_year < 1886) throw std::out_of_range("Production year out of range"); // 1886 - first car prod
    if (fuel_type.empty()) throw std::invalid_argument("Fuel type cannot be empty");
    if (car_self_weight > 44000 || car_self_weight < 400) throw std::out_of_range("Car self weight out of range"); // real values from internet
    if (car_max_weight < car_self_weight) throw std::out_of_range("Car max weight value is incorrect");
    if (people_capacity > 400 || people_capacity < 0) throw std::out_of_range("People capacity out of range");
    if (power > 2500 || power < 90) throw std::out_of_range("Power out of range");
    if (fuel_capacity < 30 || fuel_capacity > 1500) throw std::out_of_range("Fuel capacity out of range");
    if (fuel_amount > fuel_capacity || fuel_amount < 0) throw std::out_of_range("Fuel amount is incorrect");
    if (fuel_consumption < 0 ) throw std::out_of_range("Fuel consumption out of range");
    CarId::ClaimId(id);
    this -> Id = id;
}

Car::~Car() { CarId::UnclaimId(this -> Id); }

Car::Car(Car &&other_car) noexcept :
    Brand(std::move(other_car.Brand)),
    Model(std::move(other_car.Model)),
    ProductionYear(other_car.ProductionYear),
    FuelType(std::move(other_car.FuelType)),
    CarSelfWeight(other_car.CarSelfWeight),
    CarMaxWeight(other_car.CarMaxWeight),
    PeopleCapacity(other_car.PeopleCapacity),
    Power(other_car.Power),
    FuelAmount(other_car.FuelAmount),
    FuelCapacity(other_car.FuelCapacity),
    FuelConsumption(other_car.FuelConsumption),
    People(std::move(other_car.People)),
    Id(std::move(other_car.Id)) {
    other_car.Id = "";
    {
        other_car.People.clear();
    }
}

std::string Car::getBrand() const { return Brand; }
std::string Car::getModel() const { return Model; }
int Car::getProductionYear() const { return ProductionYear; }
std::string Car::getFuelType() const { return FuelType; }
double Car::getCarSelfWeight() const { return CarSelfWeight; }
double Car::getCarMaxWeight() const { return CarMaxWeight; }
int Car::getPeopleCapacity() const { return PeopleCapacity; }
double Car::getPower() const { return Power; }
double Car::getFuelAmount() const { return FuelAmount; }
double Car::getFuelCapacity() const { return FuelCapacity; }
double Car::getFuelConsumption() const { return FuelConsumption; }
std::string Car::getId() const { return Id; }

void Car::setFuelAmount(double new_fuel_amount) {
    if (new_fuel_amount < 0 || new_fuel_amount > FuelCapacity) throw std::out_of_range("Fuel amount out of range");
    FuelAmount = new_fuel_amount;
}

double Car::calculateDistance() const {
    double distance = (FuelAmount * Power * CarSelfWeight * FuelConsumption) / (100 * Power * (CarSelfWeight + getPeopleWeightSum()));
    return distance;
}

void Car::addPerson(const Person &person) {
    if (People.size() >= PeopleCapacity) throw std::out_of_range("People limit reached in car");

    double new_people_weight_sum = getPeopleWeightSum() + person.getWeight();
    if (new_people_weight_sum > CarMaxWeight) throw std::out_of_range("Car max weight reached in car");

    People.emplace_back(person.getName(), person.getWeight());
}

void Car::removePerson(const std::string& fullName) {
    auto it = std::find_if(People.begin(), People.end(),
        [&fullName](const Person& p) { return p.getName() == fullName; });

    if (it != People.end()) {
        People.erase(it);
    } else {
        throw std::invalid_argument("No such person in car");
    }
}

void Car::removePerson(const std::string& fullName, double weight) {
    auto it = std::find_if(People.begin(), People.end(),
        [&fullName, weight](const Person& p) {
            return p.getName() == fullName && p.getWeight() == weight;
        });

    if (it != People.end()) {
        People.erase(it);
    } else {
        throw std::invalid_argument("Person with given name and weight not found in the car");
    }
}

void Car::dropAll() {
    People.clear();
}

std::vector<Person> Car::getPersons() const {
    return People;
}

double Car::getPeopleWeightSum() const {
    double sum = 0;
    for (const auto& person : People) {
        sum += person.getWeight();
    }
    return sum;
}

void Car::printPeopleList() const {
    if (People.empty()) {
        std::cout << "The car is empty" << std::endl;
        return;
    }

    std::cout << "People in the car: " << std::endl;
    for (const auto& person : People) {
        std::cout << person.getName() << " " << person.getWeight() << " kg" << std::endl;
    }
}