//
// Created by Vincent Morin on 2021-12-21.
//

#include "Car.h"

int main() {
    Car car{};
    Car car2{6};
    car.FillFuel(6);
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Dashboard();
    return 0;
}