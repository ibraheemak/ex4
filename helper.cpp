#include "helper.h"
  void enterSize(int& teamSize)
{
    printEnterTeamSizeMessage();
     cin>>teamSize;
    while(teamSize<2 || teamSize>6){
      printInvalidTeamSize();
      printEnterTeamSizeMessage();
      cin>>teamSize;
    }
}

void readCard(const string& type,int line,deque<shared_ptr<Card>>& cards)
{
  shared_ptr<Card> card;
  if(type=="Witch"){
    card=shared_ptr<Card>(new Witch);
  }
  else if(type=="Well"){
    card=shared_ptr<Card>(new Well);
  }
  else if(type=="Treasure"){
    card=shared_ptr<Card>(new Treasure);
  }
  else if(type=="Merchant"){
    card=shared_ptr<Card>(new Merchant);
  }
  else if(type=="Mana"){
    card=shared_ptr<Card>(new Mana);
  }
  else if(type=="Gremlin"){
    card=shared_ptr<Card>(new Gremlin);
  }
  else if(type=="Dragon") {
    card=shared_ptr<Card>(new Dragon);
  }
   else if(type=="Barfight"){
    card=shared_ptr<Card>(new Barfight);
  }
  else{
    throw DeckFileFormatError(line);
  }
  cards.push(card);
}

bool readPlayerType(const string& name,const string &playerType,deque<shared_ptr<Player>>& players)
{
  shared_ptr<Player> player;
  if(playerType=="Warrior")
  {
    player=shared_ptr<Player>(new Warrior(name));
  }
  else if(playerType=="Ninja")
  {
    player=shared_ptr<Player>(new Ninja(name));
  }
   else if(playerType=="Healer")
  {
    player=shared_ptr<Player>(new Healer(name));
  }
  else
  {
    return false;
  }
  if(checkName(name))
  {
  players.push_back(player);
  return true;
  }
return false;
}

void readPlayer(deque<shared_ptr<Player>>& players,int teamSize)
{
  string playerName,playerType;
  for(int i=0;i<teamSize;i++)
  {
    cin>>playerName;
    cin>>playerType;
    while (!checkName(playerName)||!readPlayerType(playerName,playerType,players))
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


bool checkName(const string& name)
{
  for (int i=0;i<name.size();i++)
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