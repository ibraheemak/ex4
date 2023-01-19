#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include <fstream>
#include "Exception.h"
using std::ifstream;
#include <string>
#include "utilities.h"
#include <deque>
#include "Cards/Witch.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include <memory> //!! I added this for me
#include <vector>
class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    void readCardAux(const string& type,int line);
    void readPlayerAux(int teamSize);
    bool readPlayerType(const string& name,const string &playerType);
    bool checkName(const string& name);
    int enterSize(string& teamSize);
    deque<unique_ptr<Card>> m_cards;
    deque<shared_ptr<Player>> m_players;
    int m_numOfRounds; // add it to constructor
    // int m_teamSize;
    deque<shared_ptr<Player>> m_winnersLeaderBoard;
    deque<shared_ptr<Player>> m_losersLeaderBoard;
    int m_numOfWinners;
    int m_numOfLosers;
    int m_numOfAllPlayer;

};



#endif /* MTMCHKIN_H_ */