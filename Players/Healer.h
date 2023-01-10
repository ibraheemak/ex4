#ifndef HW4_HEALER_H
#define HW4_HEALER_H
#include <iostream>
#include "Player.h"

class Healer : public Player
{
public:
explicit Healer(const string playerName);
void heal(int addHeal) override;//add heal to the player
const string getType()const override;


};
 #endif