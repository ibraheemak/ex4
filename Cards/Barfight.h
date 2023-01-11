#ifndef CARD_BARDFIGHT_H
#define CARD_BARDFIGHT_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;

class Barfight: public Card{
public:
    explicit Barfight(string name);
    Barfight(Barfight&)=default;
    ~Barfight() override=default;
    void Encounter(Player& player) const override;
private:
    static const int BARFIGHT_DAMAGE=10;
};



#endif