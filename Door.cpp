//
// Created by federico on 27/09/19.
//

#include "Door.h"

Door::Door(int levelNumber, int doorNumber, std::string texturePath, int id) : Item(texturePath, id) {

}

void Door::interact(GameHero *player, Map &map) {

}

void Door::update(Map *map) {
    Item::update(map);
}