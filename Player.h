#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Player {
    private:
        vector<Item*> inventory;
        int health;

    public:
        Player() {
            health = 50;
        }

        bool collectItem(Item* item);
        Item* dropItem();
        void printInventory();
        bool hasItem(Item* checkItem);
        int getHealth();
        void setHealth(int newHealth);

};


#endif