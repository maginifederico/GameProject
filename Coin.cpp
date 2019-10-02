//
// Created by federico on 19/09/19.
//

#include "Coin.h"
#include "Map.h"
#include "GameHero.h"


Coin::Coin(int cV, std::string &texturePath, int id) : Item(texturePath, id, true), coinValue(cV) {



}

void Coin::interact(GameHero *player, Map &map) {

    for (int y = 0; y < map.getObjectsCollector().size(); y++)
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
        }

    player->getGui()->updateCoinCount(coinValue);

}
