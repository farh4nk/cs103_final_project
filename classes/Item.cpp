#include "Item.h"

Item::Item(string name, string desc) {
    itemName = name;
    itemDesc = desc;
}

void Item::interact() {
    cout << "interact function under construction" << endl;
}

void Item::use() {
    cout << "use function under construction" << endl;
}