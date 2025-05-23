#include "Car.h"
#include <stdexcept>
#include <chrono>

Car::Car(std::string& brand, std::string& model, int production_year, std::string& fuel_type, double car_self_weight, double car_max_weight, int people_capacity,
         double power, double fuel_amount, double fuel_capacity, std::string& id) { // todo make by init list
    if (brand.empty()) throw std::invalid_argument("Brand cannot be empty");
    if (model.empty()) throw std::invalid_argument("Model cannot be empty");
    static auto current_year = std::chrono::year_month_day{floor<std::chrono::days>(std::chrono::system_clock::now())}.year();
    if (production_year > static_cast<int>(current_year) || production_year < 1886) throw std::out_of_range("Production year out of range"); // 1886 - first car prod
    if (fuel_type.empty()) throw std::invalid_argument("Fuel type cannot be empty");
    if (car_self_weight > 44000 || car_self_weight < 400) throw std::out_of_range("Car self weight out of range");
    if (car_max_weight < car_self_weight) throw std::out_of_range("Car max weight value is incorrect");
    if (people_capacity > 400 || people_capacity < 0) throw std::out_of_range("People capacity out of range");
    if (power > 2500 || power < 90) throw std::out_of_range("Power out of range");
    if (fuel_capacity < 30 || fuel_capacity > 1500) throw std::out_of_range("Fuel capacity out of range");
    if (fuel_amount > fuel_capacity || fuel_amount < 0) throw std::out_of_range("Fuel amount is incorrect");
    this -> Brand = brand;
    this -> Model = model;
    this -> ProductionYear = production_year;
    this -> FuelType = fuel_type;
    this -> CarSelfWeight = car_self_weight;
    this -> CarMaxWeight = car_max_weight;
    this -> PeopleCapacity = people_capacity;
    this -> PeopleCount = 0;
    this -> PeopleWeightSum = 0;
    this -> FuelCapacity = fuel_capacity;
    this -> FuelAmount = fuel_amount;
    CarId::ClaimId(id);
    this -> Id = id;
}

Car::~Car() { CarId::UnclaimId(this -> Id); }

Car::Car(Car &&other_car) noexcept : Id(std::move(other_car.Id)) {
    other_car.Id = "";
}

std::string Car::getBrand() const { return Brand; }
std::string Car::getModel() const { return Model; }
int Car::getProductionYear() const { return ProductionYear; }
std::string Car::getFuelType() const { return FuelType; }
double Car::getCarSelfWeight() const { return CarSelfWeight; }
int Car::getPeopleCount() const { return PeopleCount; }
double Car::getPeopleWeightSum() const { return PeopleWeightSum; }
double Car::getPower() const { return Power; }
double Car::getFuelAmount() const { return FuelAmount; }
double Car::getFuelCapacity() const { return FuelCapacity; }
std::string Car::getId() const { return Id; }

void Car::setPeopleCount(int new_people_count) {
    if (new_people_count < 0 || new_people_count > this -> PeopleCapacity) throw std::out_of_range("People capacity out of range");
    this -> PeopleCount = new_people_count;
}

void Car::setPeopleWeightSum(double new_people_weight_sum) {
    if (new_people_weight_sum < 0 || new_people_weight_sum > this -> CarMaxWeight - this -> CarSelfWeight) throw std::out_of_range("New people weight sum value is incorrect");
    this -> PeopleWeightSum = new_people_weight_sum;
}

void Car::setFuelAmount(double new_fuel_amount) {
    if (new_fuel_amount < 0 || new_fuel_amount > this -> FuelAmount) throw std::out_of_range("Fuel amount out of range");
    this -> FuelAmount = new_fuel_amount;
}


