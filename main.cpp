#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "Player.h"
#include "Entity.h"
using namespace std;

void fight();
void win();


bool gameRunning = true;
Player player;

Item *diveKit = nullptr;
Item *fuelCanister = nullptr;
Item *scraps = nullptr;

Item* heavyMetal = nullptr;
Item* compass = nullptr;
Item* weapon = nullptr;
Item* glowingClam = nullptr;
Item* tape = nullptr;

Location *crashSite = nullptr;
Location *shallows = nullptr;
Location *currLoc = nullptr;
Location *wreckage = nullptr;
Location *undertowEntrance = nullptr;
Location *undertow = nullptr;
Location *reef = nullptr;
Location* cave = nullptr;
Location* deadEnd = nullptr;
Location* ruins = nullptr;
Location* trench = nullptr;
Location* civilization = nullptr;
Location* coralForest = nullptr;
Location* cove = nullptr;
Location* cavern = nullptr;

Location* sharkDen = nullptr;
Location* crevice = nullptr;

bool inCombat = false;
Entity* enemy = nullptr;

Entity* protag = nullptr;

bool sharkDead = false;


void printShark() {
  cout << "                 /\"*._         _\n";
  cout << "            .-*'`    `*-.._.-'/\n";
  cout << "          < * ))     ,       ( \n";
  cout << "            `*-._`._(__.--*\"`.\\ \n";
  cout << "                  `))  \n";
  cout << endl;

}

void gameOver()
{
  cout << "GAME OVER" << endl;
  gameRunning = false;
}

void showDirections() {
  cout << "Available directions:" << endl;
  if (currLoc->north){
  cout << "North" << endl;
  }
  if (currLoc->south){
  cout << "South" << endl;
  }
  if (currLoc->east){
  cout << "East" << endl;
  }
  if (currLoc->west){
  cout << "West" << endl;
  }
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

  else if (command == "H" || command == "h")
  {
    cout << "Current Health: " << player.getHealth() << "/50" << endl;
  }

  else if (command == "E" || command == "e")
  {
    if (currLoc->getItem())
    {
      bool collected = player.collectItem(currLoc->getItem());
      // player.collectItem(currLoc->getItem());
      if (collected) {
      currLoc->removeItem();
      }
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
        if (currLoc == sharkDen && !inCombat && player.hasItem(weapon) && !sharkDead) {
            fight();
        }
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

  else if (command == "Z" || command == "z")
  {
    Item* dropped = player.dropItem();

    // when trade occurs
    if (dropped == scraps && currLoc == civilization && currLoc->getItem() == nullptr) {
      cout << "The locals accept your offering!" << endl;
      currLoc->setItem(fuelCanister);
      civilization->setDesc("The locals are happy to do business with you!");
    }
  }
   else if ((command == "C" || command == "c") && (player.hasItem(compass)))
  {
    showDirections();
  }

  else if ((command == "V" || command == "v") && inCombat)
  {
    int stab = protag->attack();
    enemy->takeDmg(stab);
    cout << "You hit the shark for " << stab << "damage." << endl;
  cout << "Shark HP: " << enemy->getHealth() << endl;


  // upon defeating shark
  if (!enemy->isLiving()) {
    cout << "With your weapon and your survival skills, you managed to survive the encounter with the vicious alien shark." << endl;
    inCombat = false;
    player.setHealth(protag->getHealth());
    sharkDen->setDesc("Here lies the alien shark that was standing in your way. He seemed to be guarding something valuable.");
    sharkDead = true;
    return;
  }

  int bite = enemy->attack();
  protag->takeDmg(bite);
  cout << "The shark bit you for " << bite << "damage." << endl;
  player.setHealth(player.getHealth() - bite);


  // if player dies
  if (!protag->isLiving()) {
    cout << "The shark got the upper hand and killed you." << endl;
    gameOver();
    return;
  }
    
  }


  // checking condition depending on whether player has certain items

  if (currLoc == undertow && !(player.hasItem(heavyMetal)))
  {
    cout << "The strong currents swept you away from safety. You're lost in the sea with no way or returning. You're cooked." << endl;
    gameOver();
  }
  if (currLoc != crashSite && !(player.hasItem(diveKit)))
  {
    cout << "You dropped your dive kit and lost it in the depths of the ocean. That was the only thing keeping you alive. Nice going." << endl;
    gameOver();
  }
  if (currLoc == sharkDen && !(player.hasItem(weapon)) && !sharkDead)
  {
    cout << "Without a means to defend yourself, you were brutally attacked by the mutant alien shark lurking in the depths. You died." << endl;
    gameOver();
  }

  
}


void fight() {
printShark();
cout << "Defend yourself!" << endl;
enemy = new Entity("Alien Shark", 30, 8);
protag = new Entity("You", player.getHealth(), 7);

inCombat = true;

cout << "Press [V] to attack!" << endl;

while (inCombat && gameRunning) {
  parseCommand();
}

delete enemy;
delete protag;

}

void run()
{

  cout << "You're at the " << currLoc->getName() << "." << endl;
  cout << currLoc->getDesc() << endl;
  if (currLoc->getItem())
  {
    cout << "In front of you there is a " << currLoc->getItem()->getItemName() << "." << endl;
  }
  cout << "Interact [E]\tInventory [I]\tMove [W/A/S/D]\tHealth Bar [H]\tDrop Item [Z]\tQuit [Q]" << endl;
  if (player.hasItem(compass)) {
    cout << "Check Compass [C]" << endl;
  }
  cout << endl;
  parseCommand();
  bool hasAllItems = player.hasItem(fuelCanister) && player.hasItem(compass) && player.hasItem(tape);

if (hasAllItems && currLoc != crashSite) {
    cout << "You found all the required items! Get back to the ship!" << endl;
}
else if (hasAllItems && currLoc == crashSite) {
    win();
}

  cout << endl;


  


}

void createMap()
{
  // create items
  diveKit = new Item("Diving Kit", "Diving Kit that allows you to breathe underwater. Necessary for survival on Miller's Planet.");
  fuelCanister = new Item("Fuel Canister", "Thankfully still intact. You're definitely going to need this to repair your ship.");
  scraps = new Item("Alien Fish Scraps", "Doesn't look like these do very much. Might be worth something?");
  compass = new Item("Compass", "Now you don't have to guess where you're going!");
  heavyMetal = new Item("Heavy Metal Scrap", "This hefty piece of scrap weighs you down when you carry it. Maybe thats a good thing?");
  glowingClam = new Item("Glowing Clam", "Looks cool.");
  weapon = new Item("Sword", "Crucial in case of self-defense.");
  tape = new Item("Flex Tape", "For some reason, this planet also has flex tape. This will come in handy.");


  // create locations
  crashSite = new Location("Crash Site", "Your ship malfunctioned and landed here. You're gonna have to find a way to fix it.", diveKit);
  shallows = new Location("Shallows", "Fortunately your ship landed on a shallow spot of water. You wade around looking for something valuable but find nothing.", nullptr);
  wreckage = new Location("Underwater Wreckage", "You come across a pile of wreckage from the crash. There might be valuable parts that were lost here.", heavyMetal);
  undertowEntrance = new Location("Undertow Entrance", "You dive deeper under the surface. Up north is an area with strong currents.\nWARNING: Currents here are deadly. Make sure you are well-equipped.", nullptr);
  undertow = new Location("Undertow", "Thanks to the heavy metal, you're able to resist the current.", nullptr);
  reef = new Location("Reef", "You swim to a small reef with a few alien fish swimming around.", scraps);
  cave = new Location("Underwater Cave", "You stumble upon a cave...but there's something shiny in here.", compass);
  deadEnd = new Location("Dead End", "You reached a dead end. Not much to do here.", nullptr);
  ruins = new Location("Abyssal Ruins", "You come to a dark place with ancient ruins.", nullptr);
  trench = new Location("Forgotten Trench", "There's a deep crack in the ocean floor here. Who knows what's down there...", nullptr);
  coralForest = new Location("Coral Forest", "There seems to be glowing alien life here.", glowingClam);
  civilization = new Location("Underwater Civilization", "You found an underwater civilization! The locals here are all alien fish, and they were kind enough to offer you supplies, but they want something in return.", nullptr);
  cove = new Location("Moonlit Cove", "There might be something useful here.", weapon);
  cavern = new Location("Dark Cavern", "You made it to a dark cavern. You hear ominous sounds, and they seem to be coming from up north. Keep your guard up...", nullptr);
  sharkDen = new Location("Alien Shark Den", "There's a hungry alien shark here! You're gonna have to fight for your life.", nullptr);
  crevice = new Location("Crevice", "The shark was guarding this crevice. Surely there's something valuable here...", tape);
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
  undertow->north = cave;
  cave->south = undertow;
  cave->east = deadEnd;
  deadEnd->west = cave;

  reef->north = ruins;
  ruins->south = reef;
  ruins->north = coralForest;
  coralForest->south = ruins;
  coralForest->east = cove;
  coralForest->west = civilization;
  cove->west = coralForest;
  cove->east = cavern;
  cavern->west = cove;
  cavern->north = sharkDen;
  sharkDen->south = cavern;
  sharkDen->west = crevice;
  crevice->east = sharkDen;
  ruins->west = trench;
  trench->east = ruins;
trench->north = civilization;
civilization->south = trench;
civilization->east = coralForest;



}

void printWin() {
cout << "  __   __           __        ___       _ \n"; 
cout << "  \ \ / /__  _   _  \ \      / (_)_ __ | |\n";
cout << "   \ V / _ \| | | |  \ \ /\ / /| | '_ \| |\n";
cout << "    | | (_) | |_| |   \ V  V / | | | | |_|\n";
cout << "    |_|\___/ \__,_|    \_/\_/  |_|_| |_(_)\n";
}

void win() {
  cout << "You made it back to your ship with all the necessary parts, and you're in one piece!" << endl;
  cout << "You replace your broken navigation systems with the compass. You refuel your ship with the fuel canister so that it can get running again. And that flex tape did a great job of fixing up any breaks—it works just as advertised!" << endl;
  cout << "YOU MADE IT HOME!" << endl;
  printWin();

  if (player.getHealth() <= 10) {
    cout << "Achievement Unlocked: Last Legs" << endl;
    cout << "Make it back home with 10 health or less." << endl;
  }

  gameOver();
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
  delete tape;
  return 0;
}



/*
TO DO:
- implement mini game (fighting)
- implement ascii art
- code ending
*/