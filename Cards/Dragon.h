#ifndef CARD_BATTLECARD_DRAGON_H
#define CARD_BATTLECARD_DRAGON_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;

class Dragon: public BattleCard{
public:
    explicit Dragon(string name);
    void applyVictory(Player& player) const override;
    void applyDefeat(Player& player) const override;
    Dragon(Dragon&)= default;  //!! is this how it should be?
    ~Dragon() override = default; //!! also this?

private:
    static const int DEFAULT_POWER=25;
    static const int DEFAULT_LOOT=1000;
    static const int DEFAULT_DAMAGE=100; //!! what to do with this?//editt12
};



#endif