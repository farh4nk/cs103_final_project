#include <iostream>
#include <string>
#include "Location.h"
#include "Item.h"
using namespace std;

bool gameRunning = true;

void run() {
  
  cout << "You crash landed and ended up on Miller's Planet." << endl;
  cout << "In front of you there is a diving kit. You're gonna need it to survive here." << endl;
  cout << "Interact [E]\tQuit [Q]" << endl;
  string command;
  cin >> command;

  if (command == "Q" || "q") {
    gameRunning = false;
  }

  // if (command == "E" || command == "e") {
  //   interact();
  // }

  
}

int main() {
  while (gameRunning) {
    run();
  }

  return 0;
}
