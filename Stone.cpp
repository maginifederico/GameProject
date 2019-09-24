//
// Created by federico on 23/09/19.
//

#include "Stone.h"
#include "Map.h"

Stone::Stone(sf::FloatRect collision, std::string &texturePath, int id) : Item(texturePath, id) {

    setCollision(collision);

}

void Stone::interact(GameHero *player, Map &map) {

    player->takeDamage(damage, map);
    autoDestroy(map.getAnimatedObjects(), map.getObjectsCollector());
}

void Stone::update(Map *map) {

    int c = (int) getSprite().getPosition().x / 21;
    int r = (int) getSprite().getPosition().y / 21;

    sf::FloatRect leftDownCollision;

    leftDownCollision = map->getLayer()[1].getTile()[c + r * int(map->getWidth() / 21) +
                                                     int(map->getWidth() / 21)].getCollision();

    if (getSprite().getGlobalBounds().intersects(leftDownCollision))
        autoDestroy(map->getAnimatedObjects(), map->getObjectsCollector());
    else {
        getSprite().move(0, stoneSpeed);
        sf::FloatRect collision(getSprite().getPosition().x, getSprite().getPosition().y, 21.f, 21.f);
        setCollision(collision);
    }

}

void Stone::autoDestroy(std::vector<Item *> &animatedObjects, std::vector<Item *> &objects) {

    for (int y = 0; y < animatedObjects.size(); y++)
        if (animatedObjects[y] == this) {
            animatedObjects.erase(animatedObjects.begin() + y);
        }

    for (int y = 0; y < objects.size(); y++)
        if (objects[y] == this) {
            objects.erase(objects.begin() + y);
        }
}