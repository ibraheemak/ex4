#include "Card.h"
#include "Well.h"
#include "../Players/Ninja.h"
using namespace std;


Well::Well(string name) : Card(name){};

void Well::Encounter(Player &player) const {
    bool isNinja=true;//editt12
    try {
        const Ninja &ninja = dynamic_cast<const Ninja &>(player);
    } catch (bad_cast&){
        player.damage(FALL_DAMAGE);
        isNinja=false;//editt12
    }
    printWellMessage(isNinja);//editt12
}