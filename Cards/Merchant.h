#ifndef EX4_CARD_MERCHANT_H
#define EX4_CARD_MERCHANT_H

#include "Card.h"

const string MERCHANT = "Merchant";

class Merchant : public Card
{
public:
    Merchant();
    void Encounter(Player* player) const override;
private:
    bool AuxEncounter(Player* player, int potion, int& price) const;
    const int HEAL_COST = 5;
    const int BUFF_COST =10;
    const int PROFIT =1;
    const int NOTHING =0;
    const int HEALING=1;
    const int BUFFING =2;
    const int NO_POTION=-1;

};
#endif
