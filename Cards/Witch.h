#ifndef CARD_BATTLECARD_WITCH_H
#define CARD_BATTLECARD_WITCH_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;

class Witch: public BattleCard{
public:
    explicit Witch(string name);
    void applyVictory(Player& player) const override;
    void applyDefeat(Player& player) const override;
    Witch(Witch&)= default;  //!! is this how it should be?
    ~Witch() override = default; //!! also this?

private:
    static const int DEFAULT_POWER=11;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;
    static const int FORCE_DAMAGE=-1;
};



#endif