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
        vector<Item> items; // Items in the location
        bool visited;       // true if the location has been visited
        Location* north;    //north
        Location* east;     //east
        Location* south;    //south
        Location* west;     //west

    public:
        Location() {
            name = "";
            description = "";
        }

        Location(string locName, string locDesc, vector<string> dirs, Item locItem);
        string getName() const;
        string getDesc() const;
        vector<string> getDirections() const;
        Item getItem() const;
        bool isVisited() const;
        void setVisited(bool state);           // Mark location as visited/unvisited
        void addItem(Item item);               // Add item to location
        void removeItem(string itemName);      // Remove item from location

        // Connection Management
        void setConnections(Location* n, Location* e, Location* s, Location* w);
        Location* getNorth() const;
        Location* getEast() const;
        Location* getSouth() const;
        Location* getWest() const;
};

#endif 