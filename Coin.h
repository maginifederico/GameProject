//
// Created by federico on 19/09/19.
//

#ifndef GAME_COIN_H
#define GAME_COIN_H


#include "Item.h"

class Coin : public Item {

public:
    Coin(int coinValue, std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override;

    virtual ~Coin() {
        delete this;
    };

private:


    int coinValue;

};


#endif //GAME_COIN_H
