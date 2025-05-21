#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"

void Player::collectItem(Item* item) {
    inventory.push_back(item);
    cout << item->getItemName() << " added to inventory." << endl;
    cout << endl;
}

void Player::printInventory() {
    if (inventory.size() == 0) {
        cout << "Your inventory is empty." << endl;
    }
    else {
        cout << "Inventory: " << endl;
        for (Item* item : inventory) {
            cout << "> " << item->getItemName() << ": " << item->getItemDesc() << endl;
        }

    }
    cout << endl;
}

bool Player::hasItem(Item* checkItem) {
    for (Item* item : inventory) {
        if (item->getItemName() == checkItem->getItemName()) {
            return true;
        }
    }
    return false;
}