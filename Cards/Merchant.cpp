#include "Merchant.h"

    Merchant::Merchant():Card(MERCHANT){}


void Merchant::Encounter(Player *player) const {
    string str;
    int potion=NO_POTION;
    int price = NOTHING;
    printMerchantInitialMessageForInteractiveEncounter(cout, player->getName(), player->getCoins());
    while (potion != NOTHING && potion != HEALING && potion != BUFFING)
    {
        getline(cin, str);
        try
        {
            potion = stoi(str);
        }
        catch (const invalid_argument& e)
        {
            potion =NO_POTION;
        }
        catch (const out_of_range& e)
        {
            potion = NO_POTION;
        }

        if(potion>BUFFING||potion<NOTHING)
        {
            printInvalidInput();
        }
    }
    if (potion == HEALING) {

        if (!player->pay(HEAL_COST)) {
            printMerchantInsufficientCoins(cout);
            printMerchantSummary(cout, player->getName(), potion, price);
            return;
        }
        price = HEAL_COST;
        player->heal(PROFIT);
    }
    if (potion == BUFFING) {
        if (!player->pay(BUFF_COST)) {
            printMerchantInsufficientCoins(cout);
            printMerchantSummary(cout, player->getName(), potion, price);
            return;
        }
        price = BUFF_COST;
        player->buff(PROFIT);
    }
    printMerchantSummary(cout, player->getName(), potion, price);
}