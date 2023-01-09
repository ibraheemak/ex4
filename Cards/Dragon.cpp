
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
}

void Dragon::applyDefeat(Player &player) const {
    player.damage(player.getHP()); //!! getHp is const while damage takes a normal param, is that a problem?
}