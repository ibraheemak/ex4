#ifndef CARD_WELL_H
#define CARD_WELL_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;
const string WELL = "Well";

class Well: public Card{
public:
    Well();
    void Encounter(Player& player) const override;
private:
    static const int FALL_DAMAGE=10;
};



#endif