#pragma once

#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
        protected:
            int speed;
            Ninja(string, Point, int , int);
        public:
            Ninja();
            Ninja(string, Point);
            void move(Character *other);
            void slash(Character *other);

    };
}