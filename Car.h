#pragma once
#include "CarId.h"
#include "Person.h"
#include <string>
#include <unordered_map>
#include <vector>

class Car {
private:
    std::string Brand;
    std::string Model;
    int ProductionYear;
    std::string FuelType;
    double CarSelfWeight;
    double CarMaxWeight;
    int PeopleCapacity;
    double Power;
    double FuelAmount;
    double FuelCapacity;
    double FuelConsumption;
    std::string Id;
    std::vector<Person> People;
public:
    Car(std::string& brand, std::string& model, int production_year, std::string& fuel_type, double car_self_weight, double car_max_weight, int people_capacity,
        double power, double fuel_amount, double fuel_capacity, double fuel_consumption, std::string& id);
    ~Car();
    Car Сar(const Car&) = delete;
    Car& operator=(const Car&) = delete;
    Car() = delete;
    Car(Car&& other_car) noexcept;

    std::string getBrand() const;
    std::string getModel() const;
    int getProductionYear() const;
    std::string getFuelType() const;
    double getCarSelfWeight() const;
    double getCarMaxWeight() const;
    int getPeopleCount() const;
    int getPeopleCapacity() const;
    double getPower() const;
    double getFuelAmount() const;
    double getFuelCapacity() const;
    double getFuelConsumption() const;
    std::string getId() const ;

    void setFuelAmount(double new_fuel_amount);
    double calculateDistance() const;
    void dropAll();

    void addPerson(const Person& person);
    void removePerson(const std::string& name);
    void removePerson(const std::string& name, double weight);
    std::vector<Person> getPersons() const;
    double getPeopleWeightSum() const;
    int getPeopleCount();
};
