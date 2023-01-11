#include "Merchant.h"

void Merchant::Encounter(Player &player, ostream& os) const {

    string str;
    int potion=NO_POTION;
    int price = NOTHING;
    printMerchantInitialMessageForInteractiveEncounter(os, player.getName(), player.getCoins());
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

        if (!player.pay(HEAL_COST)) {
            printMerchantInsufficientCoins(os);
            printMerchantSummary(os, player.getName(), potion, price);
            return;
        }
        price = HEAL_COST;
        player.heal(PROFIT);
    }
    if (potion == BUFFING) {
        if (!player.pay(BUFF_COST)) {
            printMerchantInsufficientCoins(os);
            printMerchantSummary(os, player.getName(), potion, price);
            return;
        }
        price = BUFF_COST;
        player.buff(PROFIT);
    }
    printMerchantSummary(os, player.getName(), potion, price);
}