#ifndef CARD_TREASURE_H
#define CARD_TREASURE_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;
const string TREASURE = "Treasure";

class Treasure: public Card{
public:
    Treasure();
    void Encounter(Player& player) const override;
private:
    static const int TREASURE_COINS=10;
};



#endif

