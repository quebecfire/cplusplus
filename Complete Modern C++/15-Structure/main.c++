//
// Created by Vincent Morin on 2021-12-21.
//

/* Structure
 *  Create a user-defined type through keyword struct
 *  Similar to a class
 *  Default access is public
 *  Frequently used
 *      - to represent simple abstract types such as point, vector3D, etc.
 *      - for implementing function objects
 */

#include <iostream>

struct Point {
    int x;
    int y;
};

void DrawLine(int x1, int y1, int x2, int y2) {

}

void DrawLine(Point start, Point end) {
    std::cout << start.x <<std::endl;
}

int main() {
    return 0;
}