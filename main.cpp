#include <iostream>
#include <string>
#include "Location.h"
#include "Item.h"
using namespace std;

bool gameRunning = true;
Location* currentLocation = nullptr;

void initializeGame() {
  cout << "Initializing game..." << endl;

  // Create Items
  Item divingKit("Diving Kit", "Allows you to safely explore underwater.");
  cout << "Created item: " << divingKit.getName() << endl;

  Item enginePart("Engine Part", "A crucial part to power the engines.");
  cout << "Created item: " << enginePart.getName() << endl;

  Item controlPanel("Control Panel", "Restores control to the submarine.");
  cout << "Created item: " << controlPanel.getName() << endl;

  // Create Locations
  Location* submarine = new Location("Submarine", "You are inside the wrecked submarine.", {"north", "east"}, divingKit);
  cout << "Created location: " << submarine->getName() << endl;

  Location* wreckageSite = new Location("Wreckage Site", "Metal debris and wreckage are scattered around.", {"south"}, enginePart);
  Location* coralCluster = new Location("Coral Cluster", "Colorful coral formations with hidden objects.", {"west"}, controlPanel);

  // Set Connections
  submarine->setConnections(wreckageSite, coralCluster, nullptr, nullptr);
  wreckageSite->setConnections(nullptr, nullptr, submarine, nullptr);
  coralCluster->setConnections(nullptr, nullptr, nullptr, submarine);

  // Set starting location
  currentLocation = submarine;
  cout << "Starting location set to: " << currentLocation->getName() << endl;
  cout << "Current item in location: " << currentLocation->getItem().getName() << endl;
}

// Help
void displayHelp() {
  cout << "Available Commands:" << endl;
  cout << "N - Move North" << endl;
  cout << "E - Move East" << endl;
  cout << "S - Move South" << endl;
  cout << "W - Move West" << endl;
  cout << "E - Interact with item" << endl;
  cout << "Q - Quit the game" << endl;
}

//Interactions
void Interact() {
  cout << "Interact function called." << endl;  // Debug statement
  Item currentItem = currentLocation->getItem();  // Get the item in the current location
   if (currentItem.getName() != "Unknown item") {
      cout << "You see: " << currentItem.getName() << endl;
      cout << currentItem.getDescription() << endl;
  } else {
      cout << "There is nothing to interact with here." << endl;
  }
}

// Movement
void moveToLocation(Location* nextLocation) {
  if (nextLocation != nullptr) {
      currentLocation = nextLocation;
      cout << "You moved to: " << currentLocation->getName() << endl;
      cout << currentLocation->getDesc() << endl;
  } else {
      cout << "You can't move in that direction." << endl;
  }
}

// Main Game Loop

void run() {
  cout << "SUBMARINE ESCAPE GAME" << endl;  
  cout << "You crash landed and ended up on Miller's Planet." << endl;
  cout << "You must collect ket parts to repair the submachine and ascend safely" << endl;
  cout << "Type 'help' at any time to see available commands." << endl;
  cout << "In front of you there is a diving kit. You're gonna need it to survive here." << endl;
  cout << "Interact [E]\tQuit [Q]" << endl;
  string command;
  cin >> command;

  if (command == "Q" || command == "q") {
  gameRunning = false;
  } 
  else if (command == "E" || command == "e") {
  Interact();
  } 
  else {
  cout << "Invalid command. Try again." << endl;
}

  
}

int main() {
  initializeGame();
  while (gameRunning) {
  run();
  }

  return 0;
}
