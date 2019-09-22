//
// Created by federico on 22/09/19.
//

#include <iostream>
#include "HealthPill.h"
#include "Map.h"

HealthPill::HealthPill(int hPValue, std::string &texturePath, int id) : Item(texturePath, id), value(hPValue) {

}

void HealthPill::interact(GameHero *player, Map &map, int i) {

    map.getObjectsCollector().erase(map.getObjectsCollector().begin() + i);

}

