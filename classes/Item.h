#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    private:
        string itemName;
        string itemDesc;
    public:
        Item() {
            itemName = "Unknown item";
            itemDesc = "No description available.";
        }

        Item(string name, string desc);
        string getName() const;
        string getDescription() const;

        void setName(string name);
        void setDescription(string desc);

        void interact();

        void use();
};

#endif