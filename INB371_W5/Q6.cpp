/*
    Heads and Tails (c) Daniel Park 2013

    A program which tests the implementation of the LineSegment class as per Q6.
    v0.1
    ====
    -Initial creation

*/

#include <iostream>
#include "linesegment.h"
#include <string>

using namespace std;


int main()
{

    cout << "Simple test for Q5." << endl;

    Point p1 = Point(3, 1);
    Point p2 = Point(389, 2);
    LineSegment seg = LineSegment(p1, p2);

    cout << seg.Display() << endl;

    return 0;

}