/*
    LineSegment (c) Daniel Park 2013

    A program which uses the OOP features of c++ to apply point objects

    v0.1
    ====
    -Initial creation

*/

#include <iostream>
#include <sstream>
#include <string>
#include "linesegment.h"

using namespace std;
/*
constructs an empty LineSegment object.
*/
LineSegment::LineSegment()
{
    //Default (empty) constructor
}
/*
    constructs a linesegment object from two Point objects
    usage:
        LineSegment(Point p1, Point p2)
 */
LineSegment::LineSegment(Point p1, Point p2)
{
    if (p1.getX() < p2.getX())
    {
        m_leftPoint = p1;
        m_rightPoint = p2;
    }
    else
    {
        m_leftPoint = p2;
        m_rightPoint = p1;
    }
}
/*
    Destructor of the LineSegment class
 */
LineSegment::~LineSegment()
{

}
/*
    Gets the rightmost point
 */
Point LineSegment::getRight()
{
    return m_rightPoint;
}
/*
    Gets the leftmost point
 */
Point LineSegment::getLeft()
{
    return m_leftPoint;
}

/*
    Display
    Provides a string representation of the two points, going from left to right
 */
string LineSegment::Display()
{
    stringstream out;
    out << m_leftPoint.Display() << " - " << m_rightPoint.Display() << endl;
    return out.str();
}