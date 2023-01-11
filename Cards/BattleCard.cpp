#include "Card.h"
#include <algorithm>
#include <string>
#include "BattleCard.h"
using namespace std;

BattleCard::BattleCard(const string &name,int force, int loot, int damage)
: Card(name),m_power(force),m_loot(loot),m_damage(damage){}

void BattleCard::Encounter(Player &player) const {
    if(player.getAttackStrength()>=m_power){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else{
        applyDefeat(player);
    }
}

void BattleCard::applyDefeat(Player &player) const {
    player.damage(m_damage);
    printLossBattle(player.getName(),m_name);
}

void BattleCard::printInfo(ostream& os) const
{
    bool isDragon=(m_name=="Dragon");
    printMonsterDetails(os,m_power,m_damage,m_loot,isDragon);

}


