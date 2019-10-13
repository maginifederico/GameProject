//
// Created by federico on 27/09/19.
//

#include "Door.h"

Door::Door(sf::Vector2f nextSP, int nextMapID, std::string doorTexturePath, int id, bool dis) : Item(
        doorTexturePath, id), nextMapID(nextMapID), nextSpawnPoint(nextSP), disabled(dis) {

}

void Door::interact(GameHero *player, Map &map) {

}

void Door::update(Map *map) {
}

int Door::getNextMapId() const {
    return nextMapID;
}

const sf::Vector2f &Door::getNextSpawnPoint() const {
    return nextSpawnPoint;
}

bool Door::isDisabled() const {
    return disabled;
}
