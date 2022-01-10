//
// Created by Vincent Morin on 2022-01-07.
//

#include <iostream>

// Primary template
template<typename T>
T Max(T x, T y) {
    std::cout << typeid(T).name() << std::endl;
    return x > y ? x : y;
}

// Explicit Instantiation
template char Max(char x, char y);

// Explicit Specialization
template<> const char* Max<const char*>(const char* x, const char* y) {
    std::cout << "Explicit specialized function" << std::endl;
    return *x > *y ? x : y;
}


int main() {
    const char* b{"B"};
    const char* a{"A"};

    auto s = Max(a, b);
    std::cout << s << std::endl;
    return 0;
}