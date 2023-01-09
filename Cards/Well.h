#ifndef CARD_WELL_H
#define CARD_WELL_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;

class Well: public Card{
public:
    explicit Well(string name);
    Well(Well&)=default;
    ~Well() override=default;
    void Encounter(Player& player) const override;
private:
    static const int FALL_DAMAGE=10;
};



#endif