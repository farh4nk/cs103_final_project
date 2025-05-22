#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Location {
    private:
        string name;
        string description;
        Item* currItem;

    public:
        Location* north;
        Location* south;
        Location* east;
        Location* west;

        Location() {
            name = "";
            description = "";
            currItem = nullptr;
        }

        Location(string locName, string locDesc, Item* locItem);
        string getName();
        string getDesc();
        Item* getItem();
        void removeItem();
        void setItem(Item* newItem);
        void setDesc(string newDesc);
};

#endif 