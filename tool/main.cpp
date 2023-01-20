
#include "../Mtmchkin.h"


#include <iostream>
using namespace std;
const int MAX=100;


int main(){
    try {
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX){
        game.playRound();
        game.printLeaderBoard();
        }
    }
    catch(const exception& e)
    {
        cerr<< e.what()<<endl;
    }
     return 0;
}
