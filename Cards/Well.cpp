#include "Card.h"
#include "Well.h"
#include "../Players/Ninja.h"
using namespace std;


Well::Well() : Card(WELL){}

void Well::Encounter(Player* player) const {
    bool isNinja=true;
        Ninja* ninja = dynamic_cast< Ninja* >(player);
    if(ninja== nullptr){
        player->damage(FALL_DAMAGE);
        isNinja=false;
    }
    printWellMessage(isNinja);
}