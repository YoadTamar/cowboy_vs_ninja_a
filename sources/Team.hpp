#pragma once

#include <vector>
using namespace std;

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    class Team 
    {
        private:
            vector<Character*> team;
            Character* leader;
        public:
            Team(Character*);
            void add(Character* member);
            void attack(Team*);
            int stillAlive();
            void print();
    };
}