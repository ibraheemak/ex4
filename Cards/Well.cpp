#include "Card.h"
#include "Well.h"
#include "../Players/Ninja.h"
using namespace std;


Well::Well() : Card(WELL){}

void Well::Encounter(Player &player) const {
    bool isNinja=true;
    try {
        const auto &ninja = dynamic_cast<const Ninja &>(player);
    } catch (bad_cast&){
        player.damage(FALL_DAMAGE);
        isNinja=false;
    }
    printWellMessage(isNinja);
}