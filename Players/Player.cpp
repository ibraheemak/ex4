#include "Player.h"
#include "../utilities.h"
using namespace std;


Player::Player(const string playerName) : m_name(playerName),m_force(DEAFULT_FORCE),m_level(MIN_LEVEL),m_coins(INITIAL_COINS),m_HP(DEAFULT_MAX_HP) {}


// CHECK
void Player::levelUp()
{
    if (m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;

}

void Player::buff(int addForce)
{
    if(addForce>0)//edit
    {
    m_force+=addForce;
    }
}

void Player::heal(int addHeal)
{
    if (m_HP+addHeal>DEAFULT_MAX_HP)
    {
        m_HP=DEAFULT_MAX_HP;
    }
    else
    if(addHeal>0)
    {
        m_HP+=addHeal;
    }
}

void Player::damage(int damageHeal)
{
    if (damageHeal>m_HP)
    {
        m_HP=0;
    }
    else
    if(damageHeal>0)
    {
        m_HP=m_HP-damageHeal;
    }
}

bool Player::isKnockedOut() const
{
    if(m_HP==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd>0)//edit
    {
    m_coins+=coinsToAdd;
    }
}


bool Player::pay(int payAmount)
{
    if(payAmount>m_coins)
    {
        return false;
    }
    if(payAmount>0)//edit
    {
    m_coins=m_coins-payAmount;
    }
    return true;

}

int Player::getAttackStrength() const
{
    return m_force+m_level;
}

Player& Player::operator=(const Player& player1)
{
    if(this==&player1){
        return *this;
    }
    m_name=player1.m_name;
    m_level=player1.m_level;
    m_force=player1.m_force;
    m_HP=player1.m_HP;
    m_coins=player1.m_coins;
    return *this;

}

const string Player::getName() const
{
    return m_name;

}

const int Player::getForce() const
{
    return m_force;
}

const int Player::getHP() const
{
    return m_HP;
}

const int Player::getCoins() const
{
    return m_coins;
}

std::ostream& operator<<(std::ostream& os, const Player& player1)
{
    printPlayerDetails(os,player1.getName(),player1.getType(),player1.getLevel(),player1.getForce(),player1.getHP(),player1.getCoins());
    return os;
}

void Player::decreaseForce(int forceToDecrease)
{
   m_force-=forceToDecrease;   
}
