#ifndef CARD_BATTLECARD_GREMLIN_H
#define CARD_BATTLECARD_GREMLIN_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?
#include "BattleCard.h"

using namespace std;
const string GREMLIN = "Gremlin";

class Gremlin:public BattleCard{
public:
    Gremlin();
    Gremlin(Gremlin&)= default;
    ~Gremlin() override = default;

private:
    static const int DEFAULT_POWER=5;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;
};



#endif