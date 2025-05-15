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
        vector<string> directions;
        Item currItem;

    public:
        Location() {
            name = "";
            description = "";
        }

        Location(string locName, string locDesc, vector<string> dirs, Item locItem);
        string getName();
        string getDesc();
        vector<string> getDirections();
        Item getItem();
};

#endif 