#include "Location.h"

/* 
The following code for the constructor was written with the help of ChatGPT
Prompt: How can I implement tracking between locations using pointers?
*/

Location::Location(string locName, string locDesc, Item* locItem):
    name(locName), 
    description(locDesc),
    currItem(locItem),
    north(nullptr),
    south(nullptr),
    east(nullptr),
    west(nullptr) {}



string Location::getName() {
    return name;
}

string Location::getDesc() {
    return description;
}


Item* Location::getItem() {
    return currItem;
}

void Location::removeItem() {
    currItem = nullptr;
}

void Location::setItem(Item* newItem) {
    currItem = newItem;
}

void Location::setDesc(string newDesc) {
    description = newDesc;
}