//
// Created by federico on 23/09/19.
//

#include "StoneGenerator.h"
#include "Stone.h"
#include "Map.h"

StoneGenerator::StoneGenerator(float posX, float posY, std::string &texturePath, int id) : Item(texturePath, id),
                                                                                           spawnPoint(posX, posY) {
}


void StoneGenerator::update(Map *map) {

    //genera un' altra pietra ogni cooldown e le inserisce nel vettore di oggetti dinamici
    if (clock.getElapsedTime().asSeconds() > spawnTime) {
//        std::unique_ptr<Stone> stone = std::unique_ptr<Stone>(new Stone(getCollision(), stoneTexturePath, getId()));
        Stone *stone = new Stone(getCollision(), stoneTexturePath, getId());
        stone->getSprite().setPosition(spawnPoint.x, spawnPoint.y);
        map->getAnimatedObjects().push_back(stone);
        map->getObjectsCollector().push_back(stone);
        clock.restart();
    }
}
