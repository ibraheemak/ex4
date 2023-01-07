#include "Ninja.h"
void Ninja::addCoins(int coinsToAdd)
{
    if(coinsToAdd>0)
    {
    m_coins+=2*coinsToAdd;
    }
}

const string Ninja::getType()const
{
    return "Ninja";
}
Ninja::Ninja(const char* playerName) :Player(playerName){};