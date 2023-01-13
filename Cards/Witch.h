#ifndef CARD_BATTLECARD_WITCH_H
#define CARD_BATTLECARD_WITCH_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;
const string WITCH = "Witch";
class Witch: public BattleCard{
public:
    Witch();
    void applyDefeat(Player* player) const override;

private:
    static const int DEFAULT_POWER=11;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;
    static const int FORCE_DAMAGE=-1;
};



#endif