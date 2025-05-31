#pragma once
#include "CarId.h"
#include <string>

class Car {
private:
    std::string Brand;
    std::string Model;
    int ProductionYear;
    std::string FuelType;
    double CarSelfWeight;
    double CarMaxWeight;
    int PeopleCount;
    int PeopleCapacity;
    double PeopleWeightSum;
    double Power;
    double FuelAmount;
    double FuelCapacity;
    double FuelConsumption;
    std::string Id;
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
    double getPeopleWeightSum() const;
    double getPower() const;
    double getFuelAmount() const;
    double getFuelCapacity() const;
    double getFuelConsumption() const;
    std::string getId() const ;

    void setPeopleCount(int new_people_count);
    void setPeopleWeightSum(double new_people_weightsum);
    void setFuelAmount(double new_fuel_amount);

    double calculateDistance() const;
    void dropAll();
};
