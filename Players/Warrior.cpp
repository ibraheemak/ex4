#include "Warrior.h"
int Warrior::getAttackStrength() const
{
     return 2*m_force+m_level;
}

const string Warrior::getType()const
{
    return "Warrior";
}
Warrior::Warrior(const char* playerName) :Player(playerName){};