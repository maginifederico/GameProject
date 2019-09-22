//
// Created by federico on 19/09/19.
//

#include "Coin.h"
#include "Map.h"

Coin::Coin(int cV, std::string &texturePath, int id) : Item(texturePath, id), coinValue(cV) {

}

void Coin::interact(GameHero *player, Map &map, int i) {

    map.getObjectsCollector().erase(map.getObjectsCollector().begin() + i);

}
