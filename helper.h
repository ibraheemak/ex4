#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include "utilities.h"
using namespace std;
#include "Players/Player.h"
#include "Cards/Card.h"
#include <fstream>
#include "Exception.h"
using std::ifstream;
#include <string>
#include "utilities.h"
#include <queue>
#include "Cards/Witch.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
void entersize(int& teamSize);
void readCard(const string& type,int line,queue<shared_ptr<Card>>& cards);
bool readPlayerType(const string& name,const string playerType,queue<shared_ptr<Player>>& players);
bool checkName(const string& name);
void readPlayer(queue<shared_ptr<Player>>& players,int teamSize);

#endif