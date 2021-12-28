//
// Created by Vincent Morin on 2021-12-23.
//

/* L-value
 *  - Has a name
 *  - All variables are l-values
 *  - Can be assigned values
 *  - Some expressions return l-value
 *  - L-value persists beyond the expression
 *  - Functions that return by reference return l-value
 *  - Reference to l-value (called l-value reference)
 */

/* R-value
 *  - Doesn't have a name
 *  - R-value is a temporary value
 *  - Cannot be assigned values
 *  - Some expressions return r-value
 *  - Does not persist beyond the expression
 *  - Functions that return by value return r-value
 *  - R-value reference to r-value ( called r-value reference) // Implemented in C++11, operator &&
 */

/* R-value References
 *  - A reference created to a temporary
 *  - Represents a temporary
 *  - Created with && operator
 *  - Cannot point to l-values
 *  - R-value references always bind to temporaries
 *  - L-value references always bind to l-values
 *
 *   int&& r1 = 10; // R-value reference
 *   int&& r2 = Add(5, 8); // Add returns by value (temporary)
 *   int&& r3 = 7 + 2; // Expression return a temporary
 */


#include <iostream>

// Returns by value the the returned value is of type r-value
int Add(int x, int y) {
    return x + y;
}

// Return a reference so the return value is of type l-value
int& Transform(int &x) {
    x *= x;
    return x;
}

void Print(int& x) {
    std::cout << "Print(int& x)" << std::endl;
}

//void Print(const int& x) {
//    std::cout << "Print(const int& x)" << std::endl;
//}

void Print(int&& x) {
    std::cout << "Print(int&& x)" << std::endl;
}

int main() {
    // x, y and z are l-values & 5, 10 & 8 are r-values
    int x = 5;
    int y = 10;
    int z = 8;

    // Expression returns r-value
    int result = (x + y) * z;

    // Expressions return l-value
    ++x = 6;

    int&& r1 = 10; // R-value reference
    int&& r2 = Add(5, 8); // Add returns by value (temporary)
    int&& r3 = 7 + 2; // Expression return a temporary

    //int&& r4 = x; // Impossible, we can't bind an L-value to R-value reference

    int& ref = Transform(x); // Possible, because the function return a reference.

    const int& ref2 = 3;

    Print(x);
    Print(3); // Temporaries always bind to R-values references, but they can bind to const references
    // Try with commenting bot Print function a see that it's possible

    return 0;
}