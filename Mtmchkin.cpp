#include "Mtmchkin.h"
#include <fstream>
#include "Exception.h"
using std::ifstream;
#include <string>
#include "utilities.h"
#include <queue>

  Mtmchkin::Mtmchkin(const std::string &fileName)
  {
    printStartGameMessage();
    ifstream file(fileName);
    if(!file)
    {
      throw DeckFileNotFound();
    }
    queue<const string> queueCards;
     string type;
    while(!file.eof())
    {
      getline(file,type);
      queueCards.push(type);
    }






  }