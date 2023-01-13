#include "Healer.h"
void Healer::heal(int addHeal)
{
if (m_HP+2*addHeal>DEAFULT_MAX_HP)
    {
        m_HP=DEAFULT_MAX_HP;
    }
    else
    if(addHeal>0)
    {
        m_HP+=2*addHeal;
    }
}
const string Healer::getType()const
{
    return "Healer";
}

Healer::Healer(const string playerName) :Player(playerName){}