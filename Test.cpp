#include <iostream>

#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <cmath>
#include "doctest.h"

using namespace std;

namespace ariel
{
    TEST_CASE("check point func")
    {
        Point p1{0.0, 0.0};
        Point p2{1.0,1.0};

        CHECK(p1.distance(p1) == 0);
        CHECK(p1.distance(p2) == p2.distance(p1));
        CHECK(p1.distance(p2) == sqrt(2));        


    }


    TEST_CASE("Ninja sub classes - without hitpoints")
    {
        // YoungNinja young("yoad" , Point());
        // TrainedNinja trained("yoad" , Point());
        // OldNinja old("yoad" , Point());

        // CHECK(young.isAlive());
        // CHECK(young.distance(&trained) == 0.0);
        // CHECK(young.getLocation().distance(trained.getLocation()) == 0.0);

        // CHECK(trained.isAlive());
        // CHECK(trained.distance(&old) == 0.0);
        // CHECK(old.getLocation().distance(old.getLocation()) == 0.0);

        // CHECK(old.isAlive());
        // CHECK(old.distance(&young) == 0.0);
        // CHECK(old.getLocation().distance(young.getLocation()) == 0.0);
    }

    TEST_CASE("Cowboy")
    {
        Cowboy cowboy{"yoad", Point()};
        CHECK(cowboy.isAlive());
        CHECK(cowboy.hasboolets());
        CHECK_EQ(cowboy.getName(), "yoad");
        CHECK_EQ(cowboy.getLocation().distance(Point()), 0);
    }
    
    TEST_CASE("Team initialization only")
    {
        Cowboy cowboy{"yoad" , Point()};
        Cowboy cowboy2{"yoad2" , Point()};
        YoungNinja ninja{"lior", Point{}};
        YoungNinja ninja2{"lior2", Point{}};

        Team team{&cowboy};
        CHECK_EQ(team.stillAlive(), 1);
        team.add(&cowboy);
        CHECK_EQ(team.stillAlive(), 2);

        Team2 team2{&ninja};
        CHECK_EQ(team2.stillAlive(), 1);
        team2.add(&cowboy);
        CHECK_EQ(team2.stillAlive(), 2);
    }

    TEST_CASE("Team")
    {
        Cowboy cowboy{"yoad" , Point()};
        Cowboy cowboy2{"yoad2" , Point()};
        Cowboy cowboy3{"yoad3" , Point()};
        Cowboy cowboy4{"yoad4" , Point()};
        Cowboy cowboy5{"yoad5" , Point()};
        Cowboy cowboy6{"yoad6" , Point()};
        Cowboy cowboy7{"yoad7" , Point()};
        Cowboy cowboy8{"yoad8" , Point()};
        Cowboy cowboy9{"yoad9" , Point()};
        Cowboy cowboy10{"yoad10" , Point()};
        Cowboy cowboy11{"yoad11" , Point()};

        Cowboy c{"leader2" , Point()};

        Team team{&cowboy};
        Team team2{&c};

        team.add(&cowboy2);
        team.add(&cowboy3);
        team.add(&cowboy4);
        team.add(&cowboy5);
        team.add(&cowboy6);
        team.add(&cowboy7);
        team.add(&cowboy8);
        team.add(&cowboy9);
        team.add(&cowboy10);

        //11 in one team    
        CHECK_THROWS(team.add(&cowboy11));


        //in other team
        CHECK_THROWS(team2.add(&cowboy2));
    }


    TEST_CASE("battle")
    {
        Cowboy cowboy{"yoad" , Point()};
        Cowboy cowboy2{"yoad2" , Point(2.0,2.0)};
        YoungNinja ninja{"lior", Point{}};
        YoungNinja ninja2{"lior2", Point{}};

        Team team{&cowboy};
        team.add(&cowboy);

        Team2 team2{&ninja};
        team2.add(&cowboy);

        for (int i = 0; i < 6; i++)
        {
            cowboy.shoot(&ninja);
        }

        CHECK_THROWS(cowboy.shoot(&ninja));
        cowboy.reload();
        CHECK_THROWS(cowboy.shoot(&ninja));

        for (int i = 0; i < 6; i++)
        {
            cowboy.shoot(&ninja);
        }

        CHECK(!cowboy.hasboolets());
        CHECK(!ninja.isAlive());
        

        for (int i = 0; i < 3; i++)
        {
            ninja2.slash(&cowboy);
        }

        CHECK(!cowboy.isAlive());

        CHECK_THROWS(ninja2.slash(&cowboy));

        // to far!!!
        for (int i = 0; i < 3; i++)
        {
            ninja2.slash(&cowboy2);
        }

        CHECK(cowboy2.isAlive());

    }

    TEST_CASE("Team battle")
    {
        Cowboy cowboy_1{"yoad" , Point(-1,-1)};
        Cowboy cowboy_2{"yoad2" , Point()};
        YoungNinja ninja{"lior", Point{}};
        YoungNinja ninja2{"lior2", Point{-0.5,-0.5}};
        YoungNinja ninja3{"lior3", Point{0.5,0.5}};


        Team team{&cowboy_1};
        team.add(&ninja);
        team.add(&ninja2);
        team.add(&ninja3);
        team.add(&cowboy_2);

        CHECK_EQ(team.stillAlive(), 5);

        YoungNinja young_ninja("y1" , Point(0, 0));
        TrainedNinja trained_ninja("y2" , Point(1, 1));
        OldNinja old_ninja("y3" , Point(2, 2));
        YoungNinja young_ninja2("y4" , Point(3, 3));
        Cowboy cowboy("y5" , Point(-6, -6));
	    Cowboy cowboy2("y6" , Point(-7, -7));
	    Cowboy cowboy3("y7" , Point(-8, -8));

        Team team2{&young_ninja};
        team2.add(&trained_ninja);
        team2.add(&old_ninja);
        team2.add(&young_ninja2);
        team2.add(&cowboy);
        team2.add(&cowboy2);
        team2.add(&cowboy3);

        CHECK_EQ(team2.stillAlive(), 7);

        team.attack(&team2);
        team2.attack(&team);
        // only Young ninja should died
        CHECK(!young_ninja.isAlive());
        CHECK(!trained_ninja.isAlive());
        CHECK(!old_ninja.isAlive());
        CHECK(!young_ninja2.isAlive());
        
    }



}