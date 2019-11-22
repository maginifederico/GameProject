/**
 * Project Untitled
 */


#include "Map.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameHero.h"
#include "math.h"
#include "FlyingBehaviour.h"


Map::Map(float w, float h, sf::Vector2f sPoint, std::string bg, std::string grnd,
         std::string obj, int id) : width(w), height(h), spawn_point(sPoint), background(bg),
                                    ground(grnd), objects(obj), endLevel(false), mapID(id) {
    //crea 3 layer
    layer = new Layer[3]{Layer(int(width / 21), int(height / 21)), Layer(int(width / 21), int(height / 21)),
                         Layer(int(width / 21), int(height / 21))};

}

bool Map::load() {
    if (!layer[0].load(sf::Vector2u(21, 21), background))
        return -1;

    if (!layer[1].load(sf::Vector2u(21, 21), ground))
        return -1;

//    if (!layer[2].load(sf::Vector2u(21, 21), objects))
//        return -1;

    if (!layer[2].loadObject(this))
        return -1;
}


const sf::Vector2f &Map::getSpawnPoint() const {
    return spawn_point;
}

Layer *Map::getLayer() const {
    return layer;
}

float Map::getHeight() const {
    return height;
}

float Map::getWidth() const {
    return width;
}

float Map::getViewHorizontalLimitSx() const {
    return viewHorizontalLimitSX;
}

float Map::getViewHorizontalLimitDx() const {
    return viewHorizontalLimitDX;
}

float Map::getViewVerticalLimitUp() const {
    return viewVerticalLimitUP;
}

float Map::getViewVerticalLimitDown() const {
    return viewVerticalLimitDOWN;
}

void Map::setViewLimits() {

    viewHorizontalLimitSX = viewWidth / 4;
    viewHorizontalLimitDX = width - (viewWidth * 3 / 4);

    viewVerticalLimitDOWN = height - viewHeight / 2;
    viewVerticalLimitUP = viewHeight / 2;

}

const float Map::getAcceleration() const {
    return gravity;
}

const float Map::getWaterAcceleration() const {
    return waterGravity;
}

std::vector<Item *> &Map::getObjectsCollector() {
    return objectsCollector;
}

const float Map::getViewHeight() const {
    return viewHeight;
}

const float Map::getViewWidth() const {
    return viewWidth;
}

std::vector<Item *> &Map::getAnimatedObjects() {
    return movingObjects;
}

void Map::updateObjects() {

    for (int i = 0; i < movingObjects.size(); i++)
        movingObjects[i]->update(this);

}

const std::string &Map::getObjects() const {
    return objects;
}

void Map::setSpawnPoint(const sf::Vector2f &spawnPoint) {
    spawn_point = spawnPoint;
}

bool Map::isEndLevel() const {
    return endLevel;
}

void Map::setEndLevel(bool endLvl) {
    Map::endLevel = endLvl;
}

int Map::getMapId() const {
    return mapID;
}

std::vector<Enemy *> &Map::getEnemies() {
    return enemies;
}

void Map::updateEnemies(GameHero &player) {

    FlyingBehaviour *ptr;

    for (Enemy *current: enemies) {
        if (fabs(player.getSprite().getPosition().x - current->getSprite().getPosition().x) < viewWidth * 2) {
            ptr = dynamic_cast<FlyingBehaviour *> (current->getMovementBehaviour());
            if (ptr != nullptr) {
                ptr->setPlayerPosition(player.getSprite().getPosition());
            }
            current->updatePosition(*this);
        }
    }

}

std::vector<Door *> &Map::getDoors() {
    return doors;
}

/**
 * Map implementation
 */
