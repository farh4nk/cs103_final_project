#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"


void Player::collectItem(Item* item) {
    if (inventory.size() == 4) {
        cout << "Your inventory is full." << endl;
    }
    else {
    inventory.push_back(item);
    cout << item->getItemName() << " added to inventory." << endl;
    
    }
    cout << endl;
}


/* 
The following code for the dropItem function was written with the help of ChatGPT
Prompt: how do i remove a specified item from a vector in c++
Follow up prompt: why doesnt it take int as an argument
*/
void Player::dropItem() {
    int dropIndex;
    cout << "Which number item would you like to drop? NOTE: Items cannot be picked up again after being dropped." << endl;
    cin >> dropIndex;
    if (dropIndex < 0 || dropIndex >= inventory.size()) {
        cout << "Invalid item number. Nothing was dropped." << endl;
        return;
    }
    cout << "Dropped: " << inventory.at(dropIndex)->getItemName() << endl;
    inventory.erase(inventory.begin() + dropIndex);
}


void Player::printInventory() {
    if (inventory.size() == 0) {
        cout << "Your inventory is empty." << endl;
    }
    else {
        cout << "Inventory: " << endl;
        for (int i = 0; i < inventory.size(); i++) {
            
            cout << i << "- " << inventory.at(i)->getItemName() << ": " << inventory.at(i)->getItemDesc() << endl;
        }
        for (int i = 0; i < 4 - inventory.size(); i++) {
                cout << "[\tEMPTY SLOT\t]" << endl; 
            }

    }
    cout << endl;
}

bool Player::hasItem(Item* checkItem) {
    for (int i = 0; i < inventory.size(); i++) {
        Item* item = inventory.at(i);
        if (item->getItemName() == checkItem->getItemName()) {
            return true;
        }
    }
    return false;
}

int Player::getHealth() {
    return health;
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}