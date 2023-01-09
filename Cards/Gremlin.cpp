
#include <algorithm>
#include <string>
#include "../Players/Player.h"
#include "BattleCard.h"
#include "Gremlin.h"
using namespace std;

Gremlin::Gremlin(string name): BattleCard(name,DEFAULT_POWER,DEFAULT_LOOT,DEFAULT_DAMAGE){}

void Gremlin::applyVictory(Player &player) const {
    player.levelUp();
    player.addCoins(m_loot);
    }

void Gremlin::applyDefeat(Player &player) const {
    player.damage(m_damage);
}