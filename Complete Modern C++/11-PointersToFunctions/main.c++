//
// Created by Vincent Morin on 2021-12-20.
//

/* Functions Pointers
 * A function pointer is a pointer that hold the address of the function
 * The type is same as the signature of the function (return type & arguments)
 * Can be used to indirectly invoke the function even if the function name is not known
 * Mainly used in algorithm and classes for customization
 */

#include <iostream>

void Print (int count, char ch) {
    using namespace std;
    for (int i = 0; i < count; ++i) {
        cout << ch;
    }
    cout << endl;
}

void EndMessage() {
    using namespace std;
    cout << "End of program" << endl;
}

int main() {
    atexit(EndMessage); // Here we are passing the EndMessage address to atexit
    Print(5, '#');
    void(*pfn) (int, char) = Print;
    (*pfn)(8,'@');
    pfn(5, '+');

    std::cout << "End of main" << std::endl;
    return 0;
}