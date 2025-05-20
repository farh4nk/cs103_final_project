#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "Player.h"
using namespace std;

bool gameRunning = true;
Player player;

void run() {

  Item diveKit("Diving Kit", "Diving Kit that allows you to breathe underwater. Necessary for survival on Miller's Planet.");
  vector<string> directions = {"north"};
  Location millersPlanet("Miller's Planet", "A distant planet covered in treacherous waters all over its surface. Waves here are deadly.", directions, diveKit);

  
  cout << "You crash landed and ended up on " << millersPlanet.getName() << "." << endl;
  cout << millersPlanet.getDesc() << endl;
  cout << "In front of you there is a " << diveKit.getItem().getItemName() << "." << endl;
  cout << "Interact [E]\tQuit [Q]" << endl;
  string command;
  cin >> command;

  if (command == "Q" || command == "q") {
    gameRunning = false;
  }

  else if (command == "E" || command == "e") {
    player.collectItem(millersPlanet.getItem());
  }
   else if (command == "I" || command == "i") {
    player.printInventory();
  }

  
}

int main() {



  while (gameRunning) {
    run();
  }

  return 0;
}
