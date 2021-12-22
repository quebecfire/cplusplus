//
// Created by Vincent Morin on 2021-12-21.
//

#include <iostream>
#include "Car.h"


void Car::FillFuel(float amount) {
    fuel = amount;
}

void Car::Accelerate() {
    speed++;
    fuel -= 0.5f;
}

void Car::Brake() {
    speed = 0;
}

void Car::AddPassengers(int count) {
    passengers = count;
}

void Car::Dashboard() const {
    std::cout << "fuel: " << fuel << std::endl ;
    std::cout << "speed: " << speed << std::endl ;
    std::cout << "passengers: " << passengers << std::endl ;
}

Car::Car() {
    std::cout << "Car()" << std::endl;
}

Car::~Car() {
    std::cout << "~Car" << std::endl;
}

Car::Car(float fuel) {
    std::cout << "Car(float)" << std::endl;
    fuel = fuel;
}
