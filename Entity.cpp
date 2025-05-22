#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Item.h"
#include "Entity.h"

Entity::Entity(string n, int h, int d) {
    name = n;
    health = h;
    dmg = d;
}

string Entity::getName() {
    return name;
}

int Entity::getHealth() {
    return health;
}

void Entity::takeDmg(int dmg) {
    health -= dmg;
    if (health < 0) {
        health = 0;
    }
}

int Entity::attack() {
    // deals random amount of damage from 1 - dmg
    return rand() % dmg + 1;
}

bool Entity::isLiving() {
    return (health > 0);
}