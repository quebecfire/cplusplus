//
// Created by Vincent Morin on 2021-12-20.
//

#include <iostream>

int main() {
    using namespace std;

    int arr[] = { 1, 2, 3, 4, 5};

    cout << "For index iteration" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << endl;
    }


    cout << "For range loop iteration, no reference" << endl;
    // In this range base for loop, we are copying at every iteration, number is a new value
    for (auto number: arr) {
        cout << number << endl;
        number = 4;
    }

    cout << "For range loop iteration, with reference" << endl;
    for (auto &number: arr) {
        cout << number << endl;
        number = 4; // Here we should modify the underlying array, all entry should be 4 after the iteration
    }

    cout << "For range loop iteration, with const reference" << endl;
    for (const auto &number:arr) {
        cout << number << endl;
        //number = 3; // Impossible because we have a const ref
    }


    cout << "While loop with pointer incrementation" << endl;
    int *beg = &arr[0];
    int *end = &arr[5];
    while (beg != end) {
        cout << *beg << endl;
        ++beg;
    }

    cout << "How does a range base for loop is expanded? Here's how" << endl;

    auto &&range = arr; // && is used as a forwarding references, so the type of range will now be the type of the array
    auto begin = std::begin(range);
    auto endd = std::end(range);

    for  (;begin != endd; ++begin) {
        auto v = *begin;
    }

    // So if we want to be able to use a range base for loop, we minimally need to support begin, end, ++ and != and begin and end need to be the same type

    // But in c++17 they modified this behavior to allow different type, ex: string is terminated with a nullchr


}