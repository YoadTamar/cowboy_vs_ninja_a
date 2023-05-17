#pragma once

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        Point location;
        int hitPoints;
        string name;
    public:
    
        Character();
        Character(string , Point);
        bool isAlive();
        double distance(Character*);
        void hit(int);
        string getName();
        Point getLocation();
        string print();

    };
    
}