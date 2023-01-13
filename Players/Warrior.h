#ifndef HW4_WARRIOR_H
#define HW4_WARRIOR_H
#include <iostream>
#include "Player.h"

class Warrior : public Player
{
public:
explicit Warrior(const string& playerName);
int getAttackStrength() const override;
const string getType()const override;
};
 #endif