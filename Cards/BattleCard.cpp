#include "Card.h"
#include <algorithm>
#include <string>
#include "BattleCard.h"
using namespace std;

BattleCard::BattleCard(string name,int force, int loot, int damage)
: Card(name),m_power(force),m_loot(loot),m_damage(damage){}


void BattleCard::Encounter(Player &player) const {
    //!! does it automatically know which apply function to go to?
    if(player.getAttackStrength()>=m_power){
        applyVictory(player);
    }
    else{
        applyDefeat(player);
    }
}

void BattleCard::printInfo(ostream& os) const
{
    
    bool isDragon=(m_name=="Dragon");
    printMonsterDetails(os,m_power,m_damage,m_loot,isDragon);

}


