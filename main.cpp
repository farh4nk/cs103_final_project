#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "Player.h"
using namespace std;

bool gameRunning = true;
Player player;

Item *diveKit = nullptr;
Item *fuelCanister = nullptr;
Item *scraps = nullptr;
Location *crashSite = nullptr;
Location *shallows = nullptr;
Location *currLoc = nullptr;
Location *wreckage = nullptr;
Location *undertowEntrance = nullptr;
Location *undertow = nullptr;
Location *reef = nullptr;

void gameOver()
{
  cout << "GAME OVER" << endl;
  gameRunning = false;
}

void parseCommand()
{
  string command;
  cin >> command;

  // parsing input

  if (command == "Q" || command == "q")
  {
    gameOver();
  }

  if (command == "H" || command == "h")
  {
    cout << "Current Health: " << player.getHealth() << "/50" << endl;
  }

  else if (command == "E" || command == "e")
  {
    if (currLoc->getItem())
    {
      player.collectItem(currLoc->getItem());
      currLoc->removeItem();
    }
    else
    {
      cout << "There's nothing to interact with here." << endl;
    }
  }
  else if (command == "I" || command == "i")
  {
    player.printInventory();
  }
  else if (command == "W" || command == "w")
  {
    if (currLoc == crashSite && !(player.hasItem(diveKit)))
    {
      cout << "You need the Dive Kit to head underwater!" << endl;
    }
    else
    {
      if (currLoc->north)
      {
        currLoc = currLoc->north;
      }
      else
      {
        cout << "You can't go north from here." << endl;
      }
    }
  }
  else if (command == "A" || command == "a")
  {
    if (currLoc->west)
    {
      currLoc = currLoc->west;
    }
    else
    {
      cout << "You can't go east from here." << endl;
    }
  }
  else if (command == "S" || command == "s")
  {
    if (currLoc->south)
    {
      currLoc = currLoc->south;
    }
    else
    {
      cout << "You can't go south from here." << endl;
    }
  }
  else if (command == "D" || command == "d")
  {
    if (currLoc->east)
    {
      currLoc = currLoc->east;
    }
    else
    {
      cout << "You can't go west from here." << endl;
    }
  }

  else if (command == "D" || command == "d")
  {
    if (currLoc->east)
    {
      currLoc = currLoc->east;
    }
    else
    {
      cout << "You can't go west from here." << endl;
    }
  }
  else if (command == "Z" || command == "z")
  {
    player.dropItem();
  }


  // checking condition depending on whether player has certain items

  if (currLoc == undertow && !(player.hasItem(fuelCanister)))
  {
    cout << "The strong currents swept you away from safety. You're lost in the sea with no way or returning. You're cooked." << endl;
    gameOver();
  }
  if (currLoc != crashSite && !(player.hasItem(diveKit)))
  {
    cout << "You dropped your dive kit and lost it in the depths of the ocean. That was the only thing keeping you alive. Nice going." << endl;
    gameOver();
  }
}

void run()
{

  cout << "You're at the " << currLoc->getName() << "." << endl;
  cout << currLoc->getDesc() << endl;
  if (currLoc->getItem())
  {
    cout << "In front of you there is a " << currLoc->getItem()->getItemName() << "." << endl;
  }
  cout << "Interact [E]\tInventory [I]\tQuit [Q]\tMove [W/A/S/D]\tHealth Bar [H]\tDrop Item [Z]" << endl;
  cout << endl;
  parseCommand();
  cout << endl;
}

void createMap()
{
  // create items
  diveKit = new Item("Diving Kit", "Diving Kit that allows you to breathe underwater. Necessary for survival on Miller's Planet.");
  fuelCanister = new Item("Fuel Canister", "Thankfully still intact. Heavy enough to protect against strong currents.");
  scraps = new Item("Alien Fish Scraps", "Doesn't look like these do very much. Might be worth eating?");

  // create locations
  crashSite = new Location("Crash Site", "Your ship malfunctioned and landed here. You're gonna have to find a way to fix it.", diveKit);
  shallows = new Location("Shallows", "Fortunately your ship landed on a shallow spot of water. You wade around looking for something valuable but find nothing.", nullptr);
  wreckage = new Location("Underwater Wreckage", "You come across a pile of wreckage from the crash. There might be valuable parts that were lost here.", fuelCanister);
  undertowEntrance = new Location("Undertow Entrance", "You dive deeper under the surface. Up north is an area with strong currents.\nWARNING: Currents here are deadly. Make sure you are well-equipped.", nullptr);
  undertow = new Location("Undertow", "Thanks to the heavy fuel canister, you're able to resist the current.", nullptr);
  reef = new Location("Reef", "You swim to a small reef with a few alien fish swimming around.", scraps);

  // add more locations and items

  // connections between locations
  crashSite->north = shallows;
  shallows->south = crashSite;
  shallows->east = wreckage;
  shallows->west = reef;
  reef->east = shallows;
  wreckage->west = shallows;
  wreckage->east = undertowEntrance;
  undertowEntrance->west = wreckage;
  undertowEntrance->north = undertow;
  undertow->south = undertowEntrance;
}

int main()
{
  cout << "You crash landed and ended up on Miller's planet, a distant planet covered in treacherous waters all over its surface. The waves here are deadly." << endl;
  cout << "You only have enough storage on you to carry 4 items. Use it wisely." << endl;

  createMap();
  currLoc = crashSite;

  while (gameRunning)
  {
    run();
  }

  // free up memory after game loop is done running
  delete crashSite;
  delete diveKit;
  delete shallows;
  delete fuelCanister;
  delete scraps;
  delete undertowEntrance;
  delete undertow;
  delete reef;
  delete wreckage;

  return 0;
}



/*
TO DO:
- finish drawing map and assigning items
- implement mini game (fighting)
- implement ascii art
- code ending
*/