#ifndef CARD_BATTLECARD_DRAGON_H
#define CARD_BATTLECARD_DRAGON_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;
const string DRAGON = "Dragon";

class Dragon: public BattleCard{
public:
    Dragon();

private:
    static const int DEFAULT_POWER=25;
    static const int DEFAULT_LOOT=1000;
    static const int DEFAULT_DAMAGE=100;
};
#endif