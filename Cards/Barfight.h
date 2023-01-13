#ifndef CARD_BARFIGHT_H
#define CARD_BARFIGHT_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"
using namespace std;

const string BARFIGHT = "Barfight";
class Barfight: public Card{
public:
    Barfight();
    Barfight(Barfight&)=default;
    ~Barfight() override=default;
    void Encounter(Player* player) const override;
private:
    static const int BARFIGHT_DAMAGE=10;
};



#endif