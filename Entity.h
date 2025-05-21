#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Entity {
    private:
        string type;

    public:
        Entity() {
            type = "";
        }
        Entity(string type);
        void trade();
        void fight();

};

#endif