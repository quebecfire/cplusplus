//
// Created by Vincent Morin on 2021-12-20.
//


/*
 * C/C++ programs are provided with different types of memory areas
 *  - stack - allocated automatically for local variables
 *  - data section - allocated for global and static data
 *  - heap - allocated at runtime
 *
 * All the memory is taken from the process address space
 * C/C++ programs provide support for memory allocation at runtime
 * Allocations on the heap have to be managed by the programmer
 * Stack and data section allocations are managed by the runtime
 *
 * C provides various functions for allocating memory from the heap
 *  - malloc: allocate raw memory on the heap, malloc is a function
 *  - calloc: allocate memory on the heap and initializes it to zero
 *  - realloc: allocates larger chunk of memory for an existing allocation
 *  - free: deallocates/releases the memory allocated through the above functions
 *
 *  Remember a free call on an unallocated memory address will panic
 *  Remember a malloc without a free will generate memory leak
 *  Remember in C, the compiler can do the implicite conversion from void * to the required type, not in c++ compiler
 *
 * C++ provides two operators for dynamic memory allocation
 *  new: allocates memory on the heap, this is not a function, it is an operator
 *  delete: deallocates memory
 *
 * Memory that is allocated through new has to be released with delete
 *
 */

#include <iostream>

void New() {
    int* p = new int{5}; // here we are allocating the memory and initilalize the memory to 5
    *p = 6;
    std::cout << *p << std::endl;
    delete p; // We have generated a dangling pointer
    p = nullptr; // now we are ok
}

void NewArray() {
    int* p = new int[5]{}; // Defaulted to zero initialisation
    for (int i = 0; i < 5; ++i) {
        std::cout << p[i] << std::endl;
    }
    delete []p;
}

void Strings() {
    char* p = new char[4];
    std::strcpy(p, "c++"); // Automatically assign a null after the copy
    delete []p;
}

void TwoD() {
    int* p1 = new int[3];
    int* p2 = new int[3];
    int** pData = new int*[2];
    pData[0] = p1;
    pData[1] = p2;
    delete []p1;
    delete []p2;
    delete []pData;
}

int main() {
    New();
    NewArray();
    Strings();
    return 0;
}