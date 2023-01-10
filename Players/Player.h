#ifndef HW4_PLAYER_H
#define HW4_PLAYER_H
#include <iostream>
using namespace std;



class Player
{

    string m_name;//name of the player
    static const int DEAFULT_FORCE=5;
    static const int MIN_LEVEL=1;
    static const int MIN_COINS=0;
    static const int MAX_LEVEL=10;
    static const int INITIAL_COINS=10;

protected:
    int m_force;//force of the player
    int m_coins;// the coins that the player have
    int m_HP;//current health of the player
    int m_level;//current level of the player
    static const int DEAFULT_MAX_HP=100;


public:
    explicit Player(const string playerName);//constructor
    Player(const Player&)=default;//copy constructor
    virtual ~Player()=default;


    friend std::ostream& operator<<(std::ostream& os, const Player& player1);//printing the player info without changing anything
    void levelUp();// raise the player level
    int getLevel() const;// return the player level
    void buff(int addForce);//add force to the player
    virtual void heal(int addHeal);//add heal to the player
    void damage(int damageHeal);//reduce heal
    bool isKnockedOut() const;//check if the player lose
    virtual void addCoins(int coinsToAdd);//add coins to the player
    bool pay(int payAmount);// reduce the coins amount that the player has
    virtual int getAttackStrength() const;//retutn the attack strenght (level+force)
    Player& operator=(const Player& player1);// operator =
    const string getName() const;//return the player name
    const int getForce() const;// return the current Force
    const int getHP() const;//return the current HP
    const int getCoins() const;//return the current coins
    virtual const string getType()const=0;//return the player type
    void decreaseForce(int forceToDecrease);





};

#endif