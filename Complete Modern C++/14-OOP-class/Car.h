//
// Created by Vincent Morin on 2021-12-21.
//

#ifndef INC_12_MEMORYMANAGEMENT_CAR_H
#define INC_12_MEMORYMANAGEMENT_CAR_H


class Car {
    float fuel{}; // Defaulted initiated when created
    float speed{};
    int passengers{};

public:
    Car(); // Default constructor, nothing to do cause already defaulted initiated
    explicit Car(float fuel);
    ~Car(); // Destructor
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard() const;
};


#endif //INC_12_MEMORYMANAGEMENT_CAR_H
