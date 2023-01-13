#include "Card.h"
#include "Mana.h"
#include "../Players/Healer.h"
using namespace std;

Mana::Mana() : Card(MANA){}


void Mana::Encounter(Player *player) const {
    bool isHealer=true;
    Healer* healer = dynamic_cast< Healer*>(player);
    if(healer== nullptr){
        isHealer=false;
    }
    else {
        player->heal(MANA_HEAL);
    }
    printManaMessage(isHealer);
}