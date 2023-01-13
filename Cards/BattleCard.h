#ifndef CARD_BATTLECARD_H
#define CARD_BATTLECARD_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?

using namespace std;

class BattleCard: public Card{

public:
    BattleCard(const string &name,int force, int loot, int damage); //!! do i need this with all the params?
    virtual ~BattleCard()=default; //!!default right?
    void Encounter(Player* player) const override;
    virtual void applyDefeat(Player* player) const; //!! should I only virtualize this?
    void printInfo(ostream& os) const override;

protected:
    int m_power;
    int m_loot;
    int m_damage;

};






#endif