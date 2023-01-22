#include "iostream"
#include "Mtmchkin.h"

void Mtmchkin::readCardAux(const string& type,int line)
{
    if(type=="Witch"){ //Vampire
        m_cards.push_back(std::move(unique_ptr<Card>(new Witch)));
    }
    else if(type=="Well"){ //Pitfall
        m_cards.push_back(std::move(unique_ptr<Card>(new Well)));
    }
    else if(type=="Treasure"){
        m_cards.push_back(std::move(unique_ptr<Card>(new Treasure)));
    }
    else if(type=="Merchant"){
        m_cards.push_back(std::move(unique_ptr<Card>(new Merchant)));
    }
    else if(type=="Mana"){ //Fairy
        m_cards.push_back(std::move(unique_ptr<Card>(new Mana)));
    }
    else if(type=="Gremlin"){ //Goblin
        m_cards.push_back(std::move(unique_ptr<Card>(new Gremlin)));
    }
    else if(type=="Dragon") {
        m_cards.push_back(std::move(unique_ptr<Card>(new Dragon)));
    }
    else if(type=="Barfight"){
        m_cards.push_back(std::move(unique_ptr<Card>(new Barfight)));
    }
    else{
        throw DeckFileFormatError(line); // redefine it with param (int& line)
    }
}

void Mtmchkin::readPlayerAux(int teamSize){
    string playerName,playerType;
    for(int i=0;i<teamSize;i++)
    {
        printInsertPlayerMessage();
        cin>>playerName;
        cin>>playerType;
        while (!checkName(playerName)||!readPlayerType(playerName,playerType))
        {
            if(!checkName(playerName))
            {
                printInvalidName();
            }
            else{
                printInvalidClass();
            }
            cin>>playerName;
            cin>>playerType;
        }
    }

}

bool Mtmchkin::readPlayerType(const string& name,const string &playerType)
{
    if(!checkName(name)){
        return false;
    }
    if(playerType=="Warrior") //Fighter
    {
        // m_players.push_back(std::move(unique_ptr<Player>(new Warrior(name))));
        m_players.push_back(shared_ptr<Player>(new Warrior(name)));
    }
    else if(playerType=="Ninja") //Rogue
    {
        // m_players.push_back(std::move(unique_ptr<Player>(new Ninja(name))));
        m_players.push_back(shared_ptr<Player>(new Ninja(name)));
    }
    else if(playerType=="Healer") //Wizard
    {
        // m_players.push_back(std::move(unique_ptr<Player>(new Healer(name))));
        m_players.push_back(shared_ptr<Player>(new Healer(name)));
    }
    else
    {
        return false;
    }
    return true;
}

bool checkName(const string& name)
{
    for(int i=0;i<(int)name.size();i++)
    {
        if(!isalpha(name[i]))
        {
            return false;
        }
    }
    if(name.size()>15)
    {
        return false;
    }
    return true;

}

int enterSize(string& tempTeamSize)
{
    bool correct=false;
    int teamSize;
    while(!correct)
    {
        correct=true;
       printEnterTeamSizeMessage();
       cin>>tempTeamSize;
       try
       {
        teamSize=stoi(tempTeamSize);
       }
       catch (const invalid_argument& e)
        {
            printInvalidTeamSize();
            correct=false;
        }
        catch (const out_of_range& e)
        {
           printInvalidTeamSize();
           correct=false;
        }
    if(correct&&(teamSize<2 || teamSize>6)){
        printInvalidTeamSize();
        correct=false;
    }
    }
    return teamSize;
}
///////////////////////////////////////////////////////////
Mtmchkin::Mtmchkin(const std::string &fileName)
{
    int cardCounter=0;
    printStartGameMessage();
    ifstream file(fileName);
    if(!file.is_open()){
        throw DeckFileNotFound();
    }
    if (file.peek() == EOF)
    {
        throw DeckFileInvalidSize();
    }
    string type;
    while(!file.eof()){
        getline(file,type);
        readCardAux(type,cardCounter);
        cardCounter++;
    }
    if(cardCounter<5){
        throw DeckFileInvalidSize();
    }
    string tempTeamSize;
    int teamSize=enterSize(tempTeamSize);
    readPlayerAux(teamSize);
    m_numOfRounds=0;
    m_numOfWinners=0;
    m_numOfLosers=0;
    m_numOfAllPlayer=(int)m_players.size();
}
// NOTE: WE USED SHARED PNT FOR PLAYERS, SO BOTH OF M_LEADERBOARD AND M_PLAYERS COULD SHARE TO THE SAME OBJECT
void Mtmchkin::playRound(){
    m_numOfRounds++;
    int numOfPlayerWhoPlayed=0; // who played this cur round
    printRoundStartMessage(m_numOfRounds);
    while(numOfPlayerWhoPlayed<m_numOfAllPlayer){
        if(  !(m_players.front()->isKnockedOut()) && !(m_players.front()->finishedTheGame()) ){
            printTurnStartMessage(m_players.front()->getName());
            m_cards.front()->Encounter(&(*m_players.front()));
            if(m_players.front()->finishedTheGame()){
                m_winnersLeaderBoard.push_back(m_players.front());
                m_numOfWinners++;
            }
            if(m_players.front()->isKnockedOut()){
                m_losersLeaderBoard.push_front(m_players.front());
                m_numOfLosers++;
            }
            m_cards.push_back(std::move(m_cards.front()));
            m_cards.pop_front();
        }
        numOfPlayerWhoPlayed++;
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
    for(const shared_ptr<Player> &curWinnerPlayer : m_winnersLeaderBoard){
        printPlayerLeaderBoard(leaderboardRank+1,*curWinnerPlayer);
        leaderboardRank++;
    }
    for(const shared_ptr<Player> &curStillPlayingPlayer : m_players) {
        if (!curStillPlayingPlayer->finishedTheGame() && !curStillPlayingPlayer->isKnockedOut()) {
            printPlayerLeaderBoard(leaderboardRank + 1, *curStillPlayingPlayer);
            leaderboardRank++;
        }
    }
    for(const shared_ptr<Player> &curLoserPlayer : m_losersLeaderBoard){
        printPlayerLeaderBoard(leaderboardRank+1,*curLoserPlayer);
        leaderboardRank++;
    }
}


bool Mtmchkin::isGameOver() const{
    return ((m_numOfLosers + m_numOfWinners)==m_numOfAllPlayer);
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numOfRounds;
}
