//
// Created by Vincent Morin on 2021-12-20.
//

/*
 * Function overloading
 *  - Two or more functions declared with the same name
 *      - Arguments should differ in type and/or number
 *      - For pointers & reference argument, qualifiers participate in overload
 *  - Different implementations of the same behaviour
 *  - The correct implementation is chosen based on the arguments
 *      - This is resolved at compile time
 *      - static polymorphism
 */

/*
 * Name Mangling
 *  - Unique names are generated by the compiler for functions
 *  - Allows linked to link the call with the correct overloaded function
 *  - Name mangling algorithm varies from compiler to compiler
 *      - Depends on the type & number of function arguments
 *      - Consequently, C++ functions are not callable from C code
 */

/*
 * extern "C"
 *  - C++ provide the compiler directive extern C
 *  - Compiler directive applied on global functions and variables
 *  - Suppresses name mangling of the type on which it is applied
 *  - Can be applied only to one function in a set of overloaded functions
 *  - Allows C++ functions to be callable from C or other languages
 *      - Apply on function declaration & definition
 *      - In .h file
 *          extern "C" <function declaration>;
 *      - In .cpp file
 *          extern "C" <function definition> {}
 *
 *  - If there's a mismatch between the .h function declaration and .cpp function definition.
 *  - The linker won't be able to link to the proper definition.
 */


#include <iostream>

int Add(int a, int b) {
    return a + b;
}

double Add(double a, double b) {
    return a + b;
}

void Print(int* x) {

}

void Print(const int* x) {

}

int main() {
    using namespace std;
    int result = Add(3, 5); // The compiler understand that we are having integer as parameter, it will call the proper Add function signature
    cout << result << endl;
    Add(3.1, 6.2); // The compiler understand that we are having double as parameter, it will cal the proper Add function signature

    const int x = 1;
    Print(&x); // Here we are invoking the overloaded Print with const int* argument

    return 0;
}