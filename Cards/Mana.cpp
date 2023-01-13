#include "Card.h"
#include "Mana.h"
#include "../Players/Healer.h"
using namespace std;

Mana::Mana() : Card(MANA){}


void Mana::Encounter(Player &player) const {
    bool isHealer=true;
    try {
         const auto &healer = dynamic_cast<const Healer &>(player);
    } catch (bad_cast&){
        isHealer=false;
    }
    if(isHealer)
    {
        player.heal(MANA_HEAL);
    }
    printManaMessage(isHealer);
   


}