
#include <algorithm>
#include <string>
#include "../Players/Player.h"
#include "BattleCard.h"
#include "Dragon.h"
using namespace std;

Dragon::Dragon(string name): BattleCard(name,DEFAULT_POWER,DEFAULT_LOOT,DEFAULT_DAMAGE){}

void Dragon::applyVictory(Player &player) const {
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.getName(),m_name);
}

void Dragon::applyDefeat(Player &player) const {
    printLossBattle(player.getName(),m_name);
    player.damage(DEFAULT_DAMAGE); //!! getHp is const while damage takes a normal param, is that a problem?
}