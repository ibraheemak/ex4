
#include "Card.h"
#include <algorithm>
#include <string>
using namespace std;

Card::Card(string name)
{
    if(name.find(' ')||name.length()>15)
    {
        throw exception(); //!! throw a proper exception
    } //!! check if its only letters
    m_name=name;

}
// the other two are default because im using string
