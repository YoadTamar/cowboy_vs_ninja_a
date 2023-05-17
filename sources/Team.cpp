#include <iostream>

using namespace std;

#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader)
    {
        this->team.push_back(leader);
    }

    void Team::add(Character *member)
    {
        this->team.push_back(member);
    }

    void Team::attack(Team *enemies) 
    {

    }

    int Team::stillAlive()
    {
        return 0;
    }

    void Team::print() 
    {
        
    }
}