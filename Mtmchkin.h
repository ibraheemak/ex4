#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include <fstream>
#include "Exception.h"
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
using std::ifstream;

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

    Mtmchkin()=delete;
    Mtmchkin(Mtmchkin &m)=delete;
    Mtmchkin& operator=(const Mtmchkin &m)=delete;

private:
    // Aux functions
    void readCardAux(const string& type,int line);
    void readPlayerAux(int teamSize);
    bool readPlayerType(const string& name,const string &playerType);
    // members
    // NOTE: WE USED SHARED PNT FOR PLAYERS, SO BOTH OF LEADERBOARD AND M_PLAYERS COULD SHARE TO THE SAME OBJECT
    deque<unique_ptr<Card>> m_cards;
    deque<shared_ptr<Player>> m_players;
    deque<shared_ptr<Player>> m_winnersLeaderBoard;
    deque<shared_ptr<Player>> m_losersLeaderBoard;
    int m_numOfRounds;
    int m_numOfWinners;
    int m_numOfLosers;
    int m_numOfAllPlayer;

};
// helpful functions:
bool checkName(const string& name);
int enterSize(string& teamSize);



#endif /* MTMCHKIN_H_ */
