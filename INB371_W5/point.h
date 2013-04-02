/*
    Point (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a point object

    v0.1
    ====
    -Initial creation

*/


#ifndef _point_h_
#define _point_h_
#include <string>

    using namespace std;

class Point
{

public:
	/*
		Constructs an empty point object
	 */
    Point();
    /*
    	Constructs a point object, with its x and y coordinates specified as arguments
     */
    Point(int x, int y);
    /*
    	Point instance destructor. Not in use
     */
    ~Point();		//TO BE IMPLEMENTED
    /*
    	gets the x coordinate of a point object
     */
    int getX();
    /*
    	gets the y coordinate of a point obaject
     */
    int getY();
    /*
    	Returns a string representation of the point object. Of the form: "[ xx, yy ]"
     */
    string Display();

private:
	int m_x, m_y;

};

#endif
