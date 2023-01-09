#include "Card.h"
#include "Barfight.h"
#include "../Players/Warrior.h"
using namespace std;


Barfight::Barfight(string name) : Card(name){};

void Barfight::Encounter(Player &player) const {
    try {
        const Warrior &warrior = dynamic_cast<const Warrior &>(player);
    } catch (bad_cast&){
        player.damage(BARFIGHT_DAMAGE);
    }

}