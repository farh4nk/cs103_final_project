#include <iostream>
#include "./Player.h"

void Player::collectItem(Item item) {
    inventory.push_back(item);
    cout << item.getItemName() << " added to inventory." << endl;
}

void Player::printInventory() {
    if (inventory.size() == 0) {
        cout << "Your inventory is empty." << endl;
    }
    else {
        cout << "Inventory: " << endl;
        for (item : inventory) {
            cout << item.getItemName() << ": " << item.getItemDesc() << endl;
        }

    }
}

bool Player::hasItem(Item checkItem) {
    for (item : inventory) {
        if (item.getItemName() == checkItem.getItemName()) {
            return true;
        }
    }
    return false;
}