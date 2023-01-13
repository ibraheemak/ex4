
#include <algorithm>
#include "../Players/Player.h"
#include "BattleCard.h"
#include "Witch.h"
using namespace std;

Witch::Witch(): BattleCard(WITCH,DEFAULT_POWER,DEFAULT_LOOT,DEFAULT_DAMAGE){}

void Witch::applyDefeat(Player* player) const {
    player->damage(m_damage);
    printLossBattle(player->getName(),m_name);
    player->decreaseForce(1);
}