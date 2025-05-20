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
            itemName = "";
            itemDesc = "";
        }

        Item(string name, string desc);

        
        string getItemName();

        string getItemDesc();
        
        void interact();

        void use();
};

#endif