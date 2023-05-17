#include <iostream>

using namespace std;

#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(string name, Point p)
    {
        this->name = name;
        this->location = p;
        this->bullets = 6;
        this->hitPoints = 110;
    }

    void Cowboy::shoot(Character* other)
    {
    }

    bool Cowboy::hasboolets()
    {
        return this->bullets > 0;
    }
    
    void Cowboy::reload()
    {
        this->bullets = 6;
    }





}