//
// Created by Vincent Morin on 2021-12-23.
//

#include "Car.h"

Car::Car() : Car(50, 0, 0) {

}

Car::Car(float fuel, int distance, int passenger) {
    this->fuel = fuel;
    this->distance = distance;
    this->passenger = passenger;
}
