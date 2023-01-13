
#include "Card.h"
using namespace std;

Card::Card(const string &name)
{
    if(name.find(' ')||name.length()>15)
    {
        throw exception(); //!! throw a proper exception
    } //!! check if its only letters
    m_name=name;

}

 void Card::printInfo(ostream& os) const
 {
    os<<m_name<<endl;

 }
ostream& operator<<(ostream& os, const Card& card)
{
    printCardDetails(os,card.m_name);
    card.printInfo(os);
    printEndOfCardDetails(os);
    return os;
}

// the other two are default because im using string
