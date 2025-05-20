#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "Player.h"
using namespace std;

bool gameRunning = true;
Player player;

Location* currLoc;
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
  else if (command == "W" || command == "w") {
    if (currLoc->north) {
      currLoc = currLoc->north;
    } 
    else {
      cout << "You can't go north from here." << endl;
    }
  }
  else if (command == "A" || command == "a") {
    if (currLoc->east) {
      currLoc = currLoc->east;
    } 
    else {
      cout << "You can't go east from here." << endl;
    }
  }
  else if (command == "S" || command == "s") {
    if (currLoc->south) {
      currLoc = currLoc->south;
    } 
    else {
      cout << "You can't go south from here." << endl;
    }
  }
  else if (command == "D" || command == "d") {
    if (currLoc->west) {
      currLoc = currLoc->west;
    } 
    else {
      cout << "You can't go west from here." << endl;
    }
  }

  cout << endl;
}

int main() {
  cout << "You crash landed and ended up on Miller's planet, a distant planet covered in treacherous waters all over its surface. The waves here are deadly." << endl;

Item* diveKit = new Item("Diving Kit", "Diving Kit that allows you to breathe underwater. Necessary for survival on Miller's Planet.");
Location* crashSite = new Location("Crash Site", "Your ship malfunctioned and crash landed here. You're gonna have to find a way to fix it.", diveKit);
Location* shallows = new Location("Shallows", "Fortunately your ship landed on a shallow spot of water. You wade around looking for something valuable but find nothing.", nullptr);
// add more locations and items

//connections between locations
crashSite->north = shallows;
shallows->south = crashSite;

currLoc = crashSite;

  while (gameRunning) {
    run();
  }


  //free up memory after game loop is done running
  delete crashSite;
  delete diveKit;
  delete shallows;
  return 0;
}
