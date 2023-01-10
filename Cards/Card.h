#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
// no need to add string, right?

using namespace std;

class Card {
public:
    explicit Card(string name); // got to check for the name applying the rules
    virtual ~Card() = default; //use default?
    Card(const Card&)=default;
    virtual void Encounter(Player& player) const=0;//editt12


protected://editt12
    string m_name;
};







#endif