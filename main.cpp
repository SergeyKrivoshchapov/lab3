#include <algorithm>

#include "Car.h"

#include <string>
#include <iostream>

int main() {
    try {
        std::string brand = "Volvo";
        std::string model = "XC90";
        int year = 2022;
        std::string fuel_type = "Diesel";
        double self_weight = 2100;
        double max_weight = 2800;
        int people_capacity= 7;
        double power = 235;
        double fuel_amount = 70;
        double fuel_capacity = 80;
        double fuel_consumption = 7.2;
        std::string id = "";

        Car Car1(brand, model, year, fuel_type, self_weight, max_weight, people_capacity, power, fuel_amount, fuel_capacity, fuel_consumption, id);

        std::cout << "Car1 created" << std::endl;
        std::cout << "Brand: " << Car1.getBrand() << std::endl;
        std::cout << "Model: " << Car1.getModel() << std::endl;
        std::cout << "Production start year: " << Car1.getProductionYear() << std::endl;
        std::cout << "Fuel type: " << Car1.getFuelType() << std::endl;
        std::cout << "Self weight: " << Car1.getCarSelfWeight() << "kg" << std::endl;
        std::cout << "Max weight: " << Car1.getCarMaxWeight() << "kg" << std::endl;
        std::cout << "People capacity: " << Car1.getPeopleCapacity() << std::endl;
        std::cout << "Power: " << Car1.getPower() << "hp" << std::endl;
        std::cout << "Fuel amount: " << Car1.getFuelAmount() << "l" << std::endl;
        std::cout << "Fuel capacity: " << Car1.getFuelCapacity() << "l" << std::endl;
        std::cout << "Fuel consumption: " << Car1.getFuelConsumption() << "l/100km"<< std::endl;
        std::cout << "Id: " << Car1.getId() << std::endl;

        Car1.setPeopleCount(3);
        Car1.setPeopleWeightSum(250);
        std::cout << "People count: " << Car1.getPeopleCount() << std::endl;
        std::cout << "People summary weight: " << Car1.getPeopleWeightSum() << "kg" << std::endl;
        std::cout << "Distance: " << Car1.calculateDistance() << "km" << std::endl;
        Car1.setFuelAmount(30);
        std::cout << "New fuel amount: " << Car1.getFuelAmount() << "l" << std::endl;
        std::cout << "New distance: " << Car1.calculateDistance() << "km" << std::endl;

        Car1.dropAll();
        std::cout << "New people count: " << Car1.getPeopleCount() << std::endl;
        std::cout << "New distance: " << Car1.calculateDistance() << "km" << std::endl;
/*
        Car Moved(std::move(Car1));
        std::cout << "Moved car id: " << Moved.getId() << std::endl;
        try {
            std::cout << "Original car id (not expected)" << Car1.getId() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Original car is empty (expected)" << std::endl;
        }
*/
/*
        try { Car InvId(brand, model, year, fuel_type, self_weight, max_weight, people_capacity, power, fuel_amount, fuel_capacity, fuel_consumption, id);
        } catch (const std::exception& e) { std::cout << e.what() <<  std::endl; }
*/
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}