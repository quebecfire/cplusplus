//
// Created by Vincent Morin on 2021-12-25.
//
#include <iostream>
#include "Integer.h"

// If you are providing any constructor implementation, the move operator become deleted implicitly
// This is why people tend to do: Rule of 5 constructor or Rule of 0 constructor
// If we provide a move implementation, then the copy get deleted
// You can reactivate with the default keyword
// Number& operator=(Number&&)=default;
// Number& operator=(const Number&)=default;

class Number {
    Integer m_Value{};
public:
    explicit Number(int value) : m_Value{value}{
    }
};

Number CreateNumber(int num) {
    Number n{num};
    return n;
}

Integer Add(const Integer& a, const Integer& b) {
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

//// Here we can see that the compiler is using copy illision and return value optimization
//// We don't see our move constructor being called
//// As of C++17, Copy Elision is guaranteed when an object is returned directly:
//// For information: https://stackoverflow.com/questions/12953127/what-are-copy-elision-and-return-value-optimization/12953150#12953150
//int main() {
//    Integer a{1}, b{3};
//    a.SetValue(Add(a, b).GetValue());
//    return 0;
//}

int main() {
    Number n1{1};
    auto n2{n1};
    n2 = n1;

    auto n3{CreateNumber(3)}; // CreateNumber return an R-value, so the compiler will choose move constructor for the number. It will also generate one for the Number class because it's not created and then call the move for Integer class
    n3 = CreateNumber(3); // Here the same thing will apply, we are passing an R-value to the functions.

    auto n4{std::move(n3)};
    // From here, we should not use anymore n3.
    // The handler number has been set with an internal pointer at nullptr
}