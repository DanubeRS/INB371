/*
 * File: interesect.cpp
 * Randomly creates 100 lines and determines where they are situated on a grid.
 */

#include <iostream>

#include "linesegment.h"
#include "random.h"

using namespace std;

const int MIDDLE = 50;
const int BOTTOM = 0;
const int TOP = 99;

int main() {
    
    Random rand;
    
    for (int i = 0; i < 100; i++) {
        
        // create two random points and put them in a line segment
        LineSegment randomLine;
        Point a = Point(rand.RandomInteger(BOTTOM, TOP), rand.RandomInteger(BOTTOM, TOP));
        Point b = Point(rand.RandomInteger(BOTTOM, TOP), rand.RandomInteger(BOTTOM, TOP));
        randomLine = LineSegment(a, b);

        // display where the line segment sits on the grid
        cout << randomLine.Display();
        if (randomLine.getRight().getX() < MIDDLE && randomLine.getLeft().getY() < MIDDLE) {
           cout << " is left of the middle." << endl;
        } else if (randomLine.getRight().getX() > MIDDLE && randomLine.getLeft().getY() > MIDDLE) {
           cout << " is right of the middle." << endl;
        } else {
           cout << " crosses the middle." << endl;
        }
    }
    
	return 0;
}
