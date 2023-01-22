#include "Merchant.h"

    Merchant::Merchant():Card(MERCHANT){}


void Merchant::Encounter(Player *player) const {
    string str;
    int potion = NO_POTION, price = NOTHING;
    printMerchantInitialMessageForInteractiveEncounter(cout, player->getName(), player->getCoins());
    do {
        cin >> str;
        try {
            potion = stoi(str);
        }
        catch (const invalid_argument &e) {
            potion = NO_POTION;
        }
        catch (const out_of_range &e) {
            potion = NO_POTION;
        }
        if (potion > BUFFING || potion < NOTHING) {

            printInvalidInput();
        }
    } while (potion != NOTHING && potion != HEALING && potion != BUFFING);
        /*
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
        */
    if (!AuxEncounter(player, potion, price)) {
        return; // when the player doesnt have sufficient coins
    }
    else {
        printMerchantSummary(cout, player->getName(), potion, price);
    }
}

bool Merchant::AuxEncounter(Player *player, int potion, int& price) const {
    if (potion == HEALING) {
        if (!player->pay(HEAL_COST)) {
            printMerchantInsufficientCoins(cout);
            printMerchantSummary(cout, player->getName(), potion, price);
            return false;
        }
        price = HEAL_COST;
        player->heal(PROFIT);
    }
    if (potion == BUFFING) {
        if (!player->pay(BUFF_COST)) {
            printMerchantInsufficientCoins(cout);
            printMerchantSummary(cout, player->getName(), potion, price);
            return false;
        }
        price = BUFF_COST;
        player->buff(PROFIT);
    }
    return true;
}
