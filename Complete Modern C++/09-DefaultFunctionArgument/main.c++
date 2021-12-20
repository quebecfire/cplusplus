//
// Created by Vincent Morin on 2021-12-20.
//

/* Default function arguments
 * Allows some or all function arguments to have a default value
 * It becomes optional to pass values to those arguments
 *  Compiler automatically assign default value if no explicit value is provided
 *  Explicit value is perferred over default value
 *
 * Default arguments should begin from the right side in the list of function arguments.
 */

#include <iostream>

void CreateWindow(const char * title, int x, int y, int width, int height);

void CreateWindow(const char * title, int x = -1, int y = -1, int width = -1, int height = -1) {
    using namespace std;
    cout << "Title: " << title << endl;
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "Width : " << width << endl;
    cout << "Height : " << height << endl;
}

int main() {
    CreateWindow("Dune");
    CreateWindow("Dune", 200, 300);
    return 0;
}