#include <iostream>

using namespace std;

#include "Character.hpp"

namespace ariel
{
        Character::Character() : name("name"), hitPoints(100), location(Point()){};

        Character::Character(string name, Point p) : name(name), hitPoints(100), location(p){};
        
        bool Character::isAlive()
        {
            return this->hitPoints > 0;
        }

        double Character::distance(Character *other)
        {
            return 0.0;
        }

        void Character::hit(int hitpoints)
        {
            this->hitPoints = this->hitPoints - hitpoints;
        }

        string Character::getName()
        {
            return this->name;
        }

        Point Character::getLocation()
        {
            return this->location;
        }
        

        string Character::print()
        {
            return "player output";
        }
}
