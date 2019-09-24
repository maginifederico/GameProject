//
// Created by federico on 22/09/19.
//

#ifndef GAME_HEALTHPILL_H
#define GAME_HEALTHPILL_H

#include "Item.h"

class HealthPill : public Item {

public:

    HealthPill(int healthPillValue, std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override;


private:

    int value;

};

#endif //GAME_HEALTHPILL_H
