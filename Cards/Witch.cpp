
#include <algorithm>
#include <string>
#include "../Players/Player.h"
#include "BattleCard.h"
#include "Witch.h"
using namespace std;

Witch::Witch(string name): BattleCard(name,DEFAULT_POWER,DEFAULT_LOOT,DEFAULT_DAMAGE){}

void Witch::applyVictory(Player &player) const {
    player.levelUp();
    player.addCoins(m_loot);
}

void Witch::applyDefeat(Player &player) const {
    player.damage(m_damage);
    // player.decreaseForce(1); //!!! need to define this
    // player.buff(FORCE_DAMAGE); // BUFF CHECKS IF ITS POSITIVE, BUT DEFAULT_DAMAGE IS NEGATIVE
}