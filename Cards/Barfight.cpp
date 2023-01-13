#include "Card.h"
#include "Barfight.h"
#include "../Players/Warrior.h"
using namespace std;


Barfight::Barfight(): Card(BARFIGHT){}

void Barfight::Encounter(Player* player) const {
    bool isWarrior=true;
    Warrior* warrior = dynamic_cast< Warrior*>(player);
    if(warrior== nullptr){
        player->damage(BARFIGHT_DAMAGE);
        isWarrior=false;
    }
    printBarfightMessage(isWarrior);
    /*
    try {
        const Warrior &warrior = dynamic_cast<const Warrior &>(player);
    } catch (bad_cast&){
        player.damage(BARFIGHT_DAMAGE);
        isWarrior=false;
    }
    */
}