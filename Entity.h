#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Entity {
    private:
        string name;
        int health;
        int dmg;

    public:
        Entity(string name, int health, int dmg);
        string getName();
        int getHealth();
        void takeDmg(int dmg);
        int attack();
        bool isLiving();

};

#endif