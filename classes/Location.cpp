#include "Location.h"

Location::Location(string locName, string locDesc, vector<string> dirs, Item locItem) {
    name = locName;
    description = locDesc;
    directions = dirs;
    currItem = locItem;

}

string Location::getName() {
    return name;
}

string Location::getDesc() {
    return description;
}

vector <string> Location::getDirections() {
    return directions;
}

Item Location::getItem() {
    return currItem;
}