/*
    Point (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a point object

    v0.1
    ====
    -Initial creation

*/


#include "point.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <sstream>  //for Display() method
#include <string>

using namespace std;


/*
    Constructs an empty point object
 */
Point::Point()
{
    //Default-constructor
}
/*
    Constructs a point object, with its x and y coordinates specified as arguments
 */
Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
}
/*
    Point instance destructor. Not in use
 */
Point::~Point()
{
    //TO BE IMPLEMENTED
}
/*
    gets the x coordinate of a point object
 */
int Point::getX()
{
    return m_x;
}
/*
    gets the y coordinate of a point object
 */
int Point::getY()
{
    return m_y;
}
/*
    Returns a string representation of the point object. Of the form: "[ xx, yy ]"
 */
string Point::Display()
{
    //Use Stringstream for editability
    stringstream out;
    out << "[\t" << m_x << ", " << m_y << "\t]";
    return out.str();   //Write stream to a string
}
