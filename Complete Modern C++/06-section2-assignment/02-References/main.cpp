/*
 * Example of command to generate de compilation environment
 * "/Users/vincentmorin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.5744.254/CLion.app/Contents/bin/cmake/mac/bin/cmake" -DCMAKE_BUILD_TYPE=Debug "-DCMAKE_MAKE_PROGRAM=/Users/vincentmorin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.5744.254/CLion.app/Contents/bin/ninja/mac/ninja" -G Ninja "/Users/vincentmorin/Repository/cplusplus/Complete Modern C++/06-section2-assignment/02-References"

 * void Add(int a, int b, int &result); add two numbers and return the sums
 * void Swap(int &a, int &b); // Swap the value of two integers
 * void Factorial(int &a, int &result); // Generate the factorial of a number and return that through the second point argument
 */

#include <iostream>

void Add(int a, int b, int &result) {
    result = a+b;  // One of the advantages of references is that you can deal with the inner value without the need of deferencing!
}

void Swap(int &a, int&b) {
    int temp{a};
    a = b;
    b = temp;
}

void Factorial(int a, int &result) {
    result = 1;
    for (int i = 0; i <= a ; i++) {
        if (i == 0)
            continue;
        result *= i;
    }
}

int main() {
    using namespace std;
    int a{1};
    int b{2};
    int result{}; // Default initialization is 0

    Add(a, b, result);
    cout << "Add 1 and 2: " <<  result << endl;

    cout << "Swaping value of a: " << a << "  and b: " << b << endl;
    Swap(a, b);
    cout << "After swap value of a: " << a << "  and b: " << b << endl;

    a = 10;
    Factorial(a, result);

    cout << "Factorial of number 10: " << result << endl;



    // Reference practices
    // The referent
    auto x{10};
    int* ptr{&x};
    // The reference
    int &ref{x};  // When a reference is created, it will ALWAYS need an initializer. A reference can't be modified after being initialized.

    // Let's prove that a reference doesn't use any memory
    cout << "Address of x: " << &x  << endl;
    cout << "Address of ref: " << &ref << endl;

    return 0;
}