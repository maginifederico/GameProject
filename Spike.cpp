//
// Created by federico on 22/09/19.
//

#include "Spike.h"
#include "Map.h"


Spike::Spike(std::string &texturePath, int id) : Item(texturePath, id) {

}

void Spike::interact(GameHero *player, Map &map) {

    player->setHP(player->getHp() - damage, map);

}
