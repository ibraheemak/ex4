#ifndef CARD_TREASURE_H
#define CARD_TREASURE_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h"

using namespace std;

class Treasure: public Card{
public:
    explicit Treasure(string name);
    Treasure(Treasure&)=default;
    ~Treasure() override=default; //!! why override?
    void Encounter(Player& player) const override;
private:
    static const int TREASURE_COINS=10;
};



#endif

