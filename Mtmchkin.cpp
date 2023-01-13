#include "iostream"
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
    enterSize(teamSize);
    readPlayer(m_players,teamSize);
      m_numOfRounds=0;
      m_numOfWinners=0;
      m_numOfLosers=0;
      m_numOfAllPlayer=(int)m_players.size();
      //!! m_leaderBoard; should we do anything here?
  }

void Mtmchkin::playRound() {
    m_leaderBoard.resize(m_numOfAllPlayer); //!! like this?
    m_numOfRounds++;
    int numOfPlayerWhoPlayed=0; // who played this cur round
    printRoundStartMessage(m_numOfRounds);
    while(numOfPlayerWhoPlayed<m_numOfAllPlayer){
        shared_ptr<Player> curPlayer= m_players.front(); //!! does this work?
        if(  !(curPlayer->isKnockedOut()) && !(curPlayer->finishedTheGame()) ){
            printTurnStartMessage(curPlayer->getName());
            m_cards.front()->Encounter(&(*curPlayer));
            if(curPlayer->finishedTheGame()){
                // m_leaderBoard.at(m_numOfWinners)=curPlayer;
                m_leaderBoard.insert(m_leaderBoard.begin()+m_numOfWinners,curPlayer);
                m_numOfWinners++;
            }
            if(curPlayer->isKnockedOut()){
                // m_leaderBoard.at(m_numOfAllPlayer-1-m_numOfLosers)=curPlayer;
                m_leaderBoard.insert(m_leaderBoard.begin()+m_numOfWinners+m_numOfLosers,curPlayer);
                m_numOfLosers++;
            }
            m_cards.push_back(m_cards.front());
            m_cards.pop_front();
            numOfPlayerWhoPlayed++;
        }
        m_players.push_back(m_players.front());
        m_players.pop_front();
    }
    if(isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const{
    printLeaderBoardStartMessage();
    int leaderboardRank=0;
    for(;leaderboardRank<m_numOfWinners;leaderboardRank++){
        printPlayerLeaderBoard(leaderboardRank+1,*m_leaderBoard.at(leaderboardRank));
        leaderboardRank++;
    }
    for(int playerIndex=0;playerIndex<m_numOfAllPlayer;playerIndex++){
        if(!m_players.at(playerIndex)->finishedTheGame() && !m_players.at(playerIndex)->isKnockedOut()){
            printPlayerLeaderBoard(leaderboardRank+1,*m_players.at(playerIndex));
            leaderboardRank++;
        }
    }
    for(int i=0;i<m_numOfLosers;i++){
        printPlayerLeaderBoard(leaderboardRank+1,*m_leaderBoard.at(leaderboardRank+i));
    }
}


bool Mtmchkin::isGameOver() const{
    return ((m_numOfLosers + m_numOfWinners)==m_numOfAllPlayer);
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numOfRounds;
}
