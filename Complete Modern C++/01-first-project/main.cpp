#include <iostream>
#include "test_class.h"

int main() {
    auto c = test_class{};
    c.test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
