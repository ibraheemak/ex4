#ifndef HW4_NINJA_H
#define HW4_NINJA_H
#include <iostream>
#include "Player.h"

class Ninja : public Player
{
public:
explicit Ninja(const char* playerName);
void addCoins(int coinsToAdd) override;//add coins to the player
const string getType()const override;
};
 #endif