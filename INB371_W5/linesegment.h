/*
    LineSegment (c) Daniel Park 2013

    A program which uses the OOP features of c++ to apply point objects

    v0.1
    ====
    -Initial creation

*/

#ifndef _linesegment_h_
#define _linesegment_h_

#include <string>
#include "point.h"

using namespace std;


class LineSegment
{
public:
    /*
        constructs an empty LineSegment object.
     */
    LineSegment();
    /*
        constructs a linesegment object from two Point objects
        usage:
            LineSegment(Point p1, Point p2)
     */
    LineSegment(Point p1, Point p2);
    /*
        Destructor of the LineSegment class
     */
    ~LineSegment();
    /*
        Gets the rightmost point
     */
    Point getRight();
    /*
        Gets the leftmost point
     */
    Point getLeft();

    /*
        Display
        Provides a string representation of the two points, going from left to right
     */
    string Display();
private:

    Point m_leftPoint, m_rightPoint;

};

#endif