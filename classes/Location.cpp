#include "Location.h"
#include <iostream>
using namespace std;

Location::Location(string locName, string locDesc, vector<string> dirs, Item locItem) {
    name = locName;
    description = locDesc;
    directions = dirs;
    currItem = locItem;
    visited = false;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;

}

string Location::getName() const{
    return name;
}

string Location::getDesc() const{
    return description;
}

vector <string> Location::getDirections() const{
    return directions;
}

Item Location::getItem() const{
    return currItem;
}
void Location::setVisited(bool state) {
    visited = state;
}

// Getter for Visited State
bool Location::isVisited() const{
    return visited;
}

// Add Item to Location
void Location::addItem(Item item) {
    items.push_back(item);
}

// Remove Item from Location
void Location::removeItem(string itemName) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getName() == itemName) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

// Set Connections to Other Locations
void Location::setConnections(Location* n, Location* e, Location* s, Location* w) {
    north = n;
    east = e;
    south = s;
    west = w;
}

// Getters for Connections
Location* Location::getNorth() const{
    return north;
}

Location* Location::getEast() const{
    return east;
}

Location* Location::getSouth() const{
    return south;
}

Location* Location::getWest() const{
    return west;
}