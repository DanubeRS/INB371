#include <iomanip>
#include <sstream>
#include <cmath>

#include "point.h"

using namespace std;

/*
    Default constructor
 */
Point::Point() {
    x = 0;
    y = 0;
}

/*
    Overloaded constructor (x and y provided)
 */
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

/*
    Destructor (unused)
 */
Point::~Point() {
    //   do nothng
}

/*
    Accessors for the points co-ordinates
 */
int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

/*
    Creates a string representation of the points co-ordinates
 */
string Point::Display() {
    stringstream s;
    s << "[" << setw(3) << x << "," << setw(3) << y << "]";
    return s.str();
}

/*
    Calculates the Eucledian distance between the calling point, and an arged point (by reference)
 */
float Point::DistanceTo(Point *dst) {

    //Calc Eucledian distance bewteen two points
    return sqrt(
               pow(abs(this->getX() - dst->getX()), 2) +
               pow(abs(this->getY() - dst->getX()), 2));


}

