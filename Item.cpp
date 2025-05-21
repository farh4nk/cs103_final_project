#include "Item.h"
#include <iostream>

Item::Item(string name, string desc) {
    itemName = name;
    itemDesc = desc;
}

string Item::getItemName() {
    return itemName;
}

string Item::getItemDesc() {
    return itemDesc;
}
