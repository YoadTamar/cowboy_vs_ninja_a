#pragma once

using namespace std;

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {       
        public:
            Team2(Character*);
            void attack(Team*);
            void print();
    };
}