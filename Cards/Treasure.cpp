#include "Card.h"
#include "Treasure.h"
using namespace std;


Treasure::Treasure(string name) : Card(name){};

void Treasure::Encounter(Player &player) const {
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();//editt12
}


