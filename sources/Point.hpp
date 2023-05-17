#pragma once

#include <iostream>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;
    public:

        Point();
        Point(double , double);
        void Print();
		static const Point &moveTowards(const Point &current, const Point &other, const double dist);
        double distance(Point);
        double getX();
        double getY();

    };
    
}