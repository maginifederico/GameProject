//
// Created by federico on 22/09/19.
//

#ifndef GAME_SPIKE_H
#define GAME_SPIKE_H


#include <string>
#include "GameCharacter.h"
#include "Map.h"
#include "GameHero.h"


class Spike : public Item {

public:

    Spike(std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override;


private:

    int damage = 10000;

};


#endif //GAME_SPIKE_H
