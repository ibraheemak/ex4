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

void readCard(const string& type,int line,deque<unique_ptr<Card>>& cards)
{
    cout<<type<<endl;
    unique_ptr<Card> card;
    if(type=="Vampire"){
        cards.push_back(std::move(unique_ptr<Card>(new Witch)));
    }
    else if(type=="Pitfall"){
        cards.push_back(std::move(unique_ptr<Card>(new Well)));
    }
    else if(type=="Treasure"){
        cards.push_back(std::move(unique_ptr<Card>(new Treasure)));
    }
    else if(type=="Merchant"){
        cards.push_back(std::move(unique_ptr<Card>(new Merchant)));
    }
    else if(type=="Fairy"){
        cards.push_back(std::move(unique_ptr<Card>(new Mana)));
    }
    else if(type=="Goblin"){
        cards.push_back(std::move(unique_ptr<Card>(new Gremlin)));
    }
    else if(type=="Dragon") {
        cout<<"successful push for Dragon"<<endl;
        cout<<"successful push for Dragon .1"<<endl;
        try {
            cards.push_back(std::move(unique_ptr<Card>(new Dragon)));
        }
        catch(std::exception &e){
            cout<<e.what()<<endl;
            cout<<"successful push for Dragon .12"<<endl;
        }
        cout<<"successful push for Dragon .2"<<endl;
    }
    else if(type=="Barfight"){
        cards.push_back(std::move(unique_ptr<Card>(new Barfight)));
    }
    else{
        throw DeckFileFormatError(line);
    }
    // cards.push_back(card);
    cout<<"successful push"<<endl;
}

bool readPlayerType(const string& name,const string &playerType,deque<shared_ptr<Player>>& players)
{
    shared_ptr<Player> player;
    if(playerType=="Fighter")
    {
        player=shared_ptr<Player>(new Warrior(name));
    }
    else if(playerType=="Rogue")
    {
        player=shared_ptr<Player>(new Ninja(name));
    }
    else if(playerType=="Wizard")
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