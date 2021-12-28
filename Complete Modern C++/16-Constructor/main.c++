//
// Created by Vincent Morin on 2021-12-23.
//

#include <iostream>

#include "Integer.h"
#include "Car.h"

int main() {
    Integer i{5}; // Creating a first object from value;
    Integer i2{i}; // Creating a second object by object copying. Even if we didn't declare a copy constructor
    // Here we have a problem, we are copying the SAME pointer in the second object.
    // But when we will exit this function scope what will happen?
    // The first object destructor will be called. here it's OK, the point is still valid
    // The second object i2 destructor is called. here it's not OK, the pointer has been deleted, meaning it's not initialized anymore.
    // This will trigger a malloc error and will abort.
    // Error :
    // 16-Constructor(9485,0x10b0fae00) malloc: *** error for object 0x7f9c59405990: pointer being freed was not allocated
    // 16-Constructor(9485,0x10b0fae00) malloc: *** set a breakpoint in malloc_error_break to debug


    // The following part is to explain difference between shallow copy and deep copy
    int* p1 = new int(5);  // new int on the heap
    // shallow copy
    int* p2 = p1; // Here the new pointer has the same reference address has the previous.
    // Under the hood, it end up to be the same pointer. No difference at all
    // This is what is happening on the default copy constructor and leading to malloc error.
    std::cout << "p1 :" << p1 << std::endl;
    std::cout << "*p1 :" << *p1 << std::endl;
    std::cout << "&p1 :" << &p1 << std::endl;

    std::cout << "p2 :" << p2 << std::endl;
    std::cout << "*p2 :" << *p1 << std::endl;
    std::cout << "&p2 :" << &p1 << std::endl;


    // Forcing a deep copy of the pointer, this the method I did implement in the Integer class to fix the error.
    int* p3 = new int{*p1};  // p3 is a different pointer, reference is not the same
    std::cout << "p3 :" << p3 << std::endl;  // p3 point to a different int location
    std::cout << "*p3 :" << *p3 << std::endl; // p3 has the same int value
    std::cout << "&p3 :" << &p3 << std::endl; // p3 is at a different memory address

    std::cout << i.GetValue() << std::endl;
    std::cout << i2.GetValue() << std::endl;


    // Let's try a delegate constructor call!
    Car car{};

    return 0; // If not provided, it will automatically return 0
}
