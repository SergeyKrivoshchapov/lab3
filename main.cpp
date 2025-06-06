#include <algorithm>

#include "Car.h"

#include <string>
#include <iostream>

int main() {
    try {
        std::string brand = "Volvo";
        std::string model = "XC90";
        std::string id = "3141592";
        int production_year = 2022;
        std::string fuel_type = "Diesel";
        double car_self_weight = 2100;
        double car_max_weight = 2800;
        int people_capacity = 7;
        double power = 235;
        double fuel_amount = 70;
        double fuel_capacity = 80;
        double fuel_consumption = 7.2;
        Car car1(brand, model, production_year, fuel_type, car_self_weight, car_max_weight, people_capacity,
                 power, fuel_amount, fuel_capacity, fuel_consumption, id);

        std::string john1_name = "John Smith";
        std::string john2_name = "John Smith";
        std::string andrew_name = "Andrew Smith";
        Person john1(john1_name, 85);
        Person john2(john2_name, 75);
        Person andrew(andrew_name, 65);

        car1.addPerson(john1);
        car1.addPerson(john2);
        car1.addPerson(andrew);
        std::cout << "added" << std::endl;
        car1.printPeopleList();

        std::cout << "removed by name" << std::endl;
        car1.removePerson("John Smith");
        car1.printPeopleList();
        std::cout << "removed by name and weight" << std::endl;
        car1.removePerson("John Smith", 75);
        car1.printPeopleList();
        car1.dropAll();
        std::cout << "dropped all" << std::endl;
        car1.printPeopleList();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
