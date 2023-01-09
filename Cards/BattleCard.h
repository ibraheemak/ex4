#ifndef CARD_BATTLECARD_H
#define CARD_BATTLECARD_H

#include <iostream>
#include <string>
#include "Card.h"
#include "../Players/Player.h" //!! right?

using namespace std;

class BattleCard: public Card{

public:
    BattleCard(string name,int power, int loot, int damage); //!! do i need this with all the params?
    BattleCard(const BattleCard&)=default; //!!default right?
    virtual ~BattleCard()=default; //!!default right?
    void Encounter(Player& player) const;
    virtual void applyVictory(Player& player) const {} // is there other way to implement this //!! with ; or {} at the end?
    virtual void applyDefeat(Player& player) const {} //!! should I only virtualize this?

protected:
    int m_power;
    int m_loot;
    int m_damage;

};






#endif