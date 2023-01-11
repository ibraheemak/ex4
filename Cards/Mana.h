#ifndef CARD_MANA_H
#define CARD_MANA_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;
const string MANA = "Mana";

class Mana: public Card{
public:
    Mana();
    Mana(Mana&)=default;
    ~Mana() override=default;
    void Encounter(Player& player) const override;
private:
    static const int MANA_HEAL=10;
};



#endif