
#include "Card.h"
using namespace std;

Card::Card(string name)
{
    if(name.find(' ')||name.length()>15)
    {
        throw exception(); //!! throw a proper exception
    } //!! check if its only letters
    m_name=name;

}


ostream& operator<<(ostream& os, const Card& card)
{
    printCardDetails(os,card.m_name);
    card.printInfo(os);
    printEndOfCardDetails(os);
    return os;
}

// the other two are default because im using string
