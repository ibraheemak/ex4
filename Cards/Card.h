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
    explicit Card(const string &name); // got to check for the name applying the rules
    Card(const Card&)=default;

    virtual void Encounter(Player& player) const=0;//editt12

    Card& operator=(const Card& anotherCard)=default;
    virtual ~Card() = default; //use default?
    friend ostream& operator<<(ostream& os, const Card& card);
    virtual void printInfo(ostream& os) const ;
    
protected://editt12
    string m_name;
};



#endif