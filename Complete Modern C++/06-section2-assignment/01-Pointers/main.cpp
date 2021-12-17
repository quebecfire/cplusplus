/*
 * int Add(int *a, int *b); add two numbers and return the sums
 * void AddVal(int *a, int *b, int *result); // add two numbers and return the sum through the third pointer argument
 * void Swap(int *a, int *b); // Swap the value of two integers
 * void Factorial(int * a, int *result); // Generate the factorial of a number and return that through the second point argument
 */

#include <iostream>

int Add(int *a, int *b) {
    return *a + *b ;
}

void AddVal(int *a, int *b, int *result) {
    *result = *a + *b ;
}

void Swap(int *a, int*b) {
    int temp{*a};
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result) {
    *result = 1;
    for (int i = 0; i <= *a ; i++) {
        if (i == 0)
            continue;
        *result *= i;
    }
}

int main() {
    using namespace std;
    int a{1};
    int b{2};
    cout << "Add 1 and 2: " <<  Add(&a, &b) << endl;

    int result{};
    AddVal(&a, &b, &result);
    cout << "Add with pointer returned: " << result << endl;

    cout << "Swaping value of a: " << a << "  and b: " << b << endl;
    Swap(&a, &b);
    cout << "After swap value of a: " << a << "  and b: " << b << endl;

    a = 10;
    Factorial(&a, &result);
    cout << "Factorial of number 10: " << result << endl;
    return 0;
}