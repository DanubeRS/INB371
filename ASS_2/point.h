#include <string>

using namespace std;

#ifndef _point_h
#define _point_h

class Point {
    public:
        
        Point();
        
        Point(int x, int y);
        
        ~Point();
        
        int getX();
        
        int getY();
        
        string Display();

        //Computes ecludian distance to the desztination point
        float DistanceTo(Point* dest);
        
    private:
        int x, y;
};

#endif
