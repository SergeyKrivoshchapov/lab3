cmake_minimum_required(VERSION 3.31)
project(lab3)

set(CMAKE_CXX_STANDARD 26)

add_executable(lab3 main.cpp
        Car.cpp
        Car.h
        CarId.cpp
        CarId.h
        Person.cpp
        Person.h)
