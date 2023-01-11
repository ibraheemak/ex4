#include "Mtmchkin.h"
#include <fstream>
#include "Exception.h"
using std::ifstream;
#include <string>
#include "utilities.h"
#include <queue>

  Mtmchkin::Mtmchkin(const std::string &fileName)
  {
    int cardCounter=0;
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
      cardCounter++;
    }
    if(cardCounter<5)
    {
      throw DeckFileInvalidSize();
    }
    int teamSize;
    printEnterTeamSizeMessage();
    cin>>teamSize;
    while(teamSize<2 || teamSize>6){
      printInvalidTeamSize();
      printEnterTeamSizeMessage();
      cin>>teamSize;
    }
    
    








  }