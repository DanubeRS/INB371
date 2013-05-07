/*
    Heads and Tails (c) Daniel Park 2013

    A program which uses the OOP features of c++ to rewrite the random interface as used in W4 tasks.
    v0.1
    ====
    -Initial creation

*/

#include <iostream>
#include "point.h"
#include <string>

using namespace std;


int main()
{

    cout << "Simple test for Q5." << endl;

    Point p1 = Point();
    Point p2 = Point(3, 2);
    cout << "Point 2 is: " << p2.getX() << " " <<  p2.getY() << endl;
    cout << "Also written as: " << p2.Display() << endl;

    return 0;

}