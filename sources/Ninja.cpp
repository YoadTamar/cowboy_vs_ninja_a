#include <iostream>

using namespace std;

#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja() : Character() , speed(0){};

    Ninja::Ninja(string name, Point p)
    {
        this->name = name;
        this->location = p;
        this->hitPoints = 110;
        this->speed = 0;
    }

    Ninja::Ninja(string name, Point p, int speed , int hitpoints)
    {
        this->name = name;
        this->location = p;
        this->hitPoints = hitpoints;
        this->speed = speed;
    }

void Ninja::move(Character *other)
{
	return;
}

void Ninja::slash(Character *other)
{
	return;
}






}