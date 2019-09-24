//
// Created by federico on 22/09/19.
//

#include <iostream>
#include "HealthPill.h"
#include "Map.h"

HealthPill::HealthPill(int hPValue, std::string &texturePath, int id) : Item(texturePath, id), value(hPValue) {

}

void HealthPill::interact(GameHero *player, Map &map) {

    for (int y = 0; y < map.getObjectsCollector().size(); y++)
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
        }

}

