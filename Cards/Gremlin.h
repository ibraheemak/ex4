#ifndef CARD_BATTLECARD_GREMLIN_H
#define CARD_BATTLECARD_GREMLIN_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;

class Gremlin:public BattleCard{
public:
    explicit Gremlin(string name);
    void applyVictory(Player& player) const override;
    void applyDefeat(Player& player) const override;
    Gremlin(Gremlin&)= default;  //!! is this how it should be?
    ~Gremlin() override = default; //!! also this?

private:
    static const int DEFAULT_POWER=5;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;
};



#endif