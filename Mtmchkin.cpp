#include "Mtmchkin.h"
#include "helper.h"


  Mtmchkin::Mtmchkin(const std::string &fileName)
  {
    int cardCounter=0;
    printStartGameMessage();
    ifstream file(fileName);
    if(!file){
      throw DeckFileNotFound();
    }
     string type;
    while(!file.eof()){
      getline(file,type);
      readCard(type,cardCounter,m_cards);
      cardCounter++;
    }
    if(cardCounter<5){
      throw DeckFileInvalidSize();
    }
    int teamSize;
    entersize(teamSize);
    readPlayer(m_players,teamSize);
  }

