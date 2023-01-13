#include "Treasure.h"
using namespace std;


Treasure::Treasure() : Card(TREASURE){}

void Treasure::Encounter(Player* player) const {
    player->addCoins(TREASURE_COINS);
    printTreasureMessage();
}


