#include <iostream>

int main() {
    // Scalar type

    // We are declaring a variable without proper initialisation
    // Then we print its value
    // We should expect random content.
    int i ;

    // We are declaring a variable properly initiated at 10.
    // Then we print its value
    // We should expect a value of 10.
    int j = 10;
    std::cout << "Uninitialized identifiers i: " << i << std::endl;
    std::cout << "Initialized identifiers j: " << j << std::endl;

    // Example of others primitives types
    char ch = 'a';
    bool flag = true; // true or false ( keywords in c++)  or 0 (false) and non-zero (true) value

    float f = 1.283f;
    double d = 521.342;

    // Vector type
    int arr[5] ;

    int arr2[5] = {1, 2, 3, 4, 5};

    // C++11 introduced uniform initialisation for Scalar type and Vector Type
    // https://www.geeksforgeeks.org/uniform-initialization-in-c/

    int arr3[5]{1,2,3,4,5};

    return 0;
}
