#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "Player.h"
using namespace std;

bool gameRunning = true;
Player player;
Item* diveKit = new Item("Diving Kit", "Diving Kit that allows you to breathe underwater. Necessary for survival on Miller's Planet.");
Location* crashSite = new Location("Crash Site", "Your ship malfunctioned and crash landed here. You're gonna have to find a way to fix it.", diveKit);
// add more locations and items here


Location* currLoc = crashSite;
void run() {

  
  cout << "You're at the " << currLoc->getName() << "." << endl;
  cout << currLoc->getDesc() << endl;
  if (currLoc->getItem()) {
  cout << "In front of you there is a " << currLoc->getItem()->getItemName() << "." << endl;
  }
  cout << "Interact [E]\tInventory [I]\tQuit [Q]\tMove [W/A/S/D]" << endl;
  cout << endl;
  string command;
  cin >> command;

  if (command == "Q" || command == "q") {
    gameRunning = false;
  }

  else if (command == "E" || command == "e") {
    if (currLoc->getItem()) {
    player.collectItem(currLoc->getItem());
    currLoc->removeItem();
    
    }
    else {
      cout << "There's nothing to interact with here." << endl;
    }
  }
   else if (command == "I" || command == "i") {
    player.printInventory();
  }

  
}

int main() {
  cout << "You crash landed and ended up on Miller's planet, a distant planet covered in treacherous waters all over its surface. The waves here are deadly." << endl;



  while (gameRunning) {
    run();
  }

  delete crashSite;
  return 0;
}
