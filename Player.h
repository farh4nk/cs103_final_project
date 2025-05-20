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

    public:
        void collectItem(Item* item);
        void printInventory();
        bool hasItem(Item* checkItem);

};


#endif