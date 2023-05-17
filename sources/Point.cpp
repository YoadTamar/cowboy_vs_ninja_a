#include <iostream>

using namespace std;

#include "Point.hpp"

namespace ariel
{
    Point::Point() : x(0), y(0) {};

    Point::Point(double x, double y) : x(x), y(y) {};

    void Point::Print()
    {
        cout << "(" << this->x << "," << this->y << ")" << endl;    
    }

    double Point::getX()
    {
        return this->x;
    }

    double Point::getY()
    {
        return this->y;
    }

	static const Point &moveTowards(const Point &current, const Point &other, const double dist)    
    {
        return current;
    }

    double Point::distance(Point)
    {
        return 1.0;
    }








}