#include "Card.h"
#include "Barfight.h"
#include "../Players/Warrior.h"
using namespace std;


Barfight::Barfight(): Card(BARFIGHT){}

void Barfight::Encounter(Player &player) const {
    bool isWarrior=true;
    try {
        const Warrior &warrior = dynamic_cast<const Warrior &>(player);
    } catch (bad_cast&){
        player.damage(BARFIGHT_DAMAGE);
        isWarrior=false;
    }
    printBarfightMessage(isWarrior);

}