/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

#include "GameCharacter.h"
#include "Layer.h"
#include "Door.h"
//#include "Enemy.h"

class Item;
class Layer;

class Enemy;

class Map {
public:
    explicit Map(float width, float height, sf::Vector2f spawnPoint, std::string background, std::string ground,
                 std::string objects, int id);

    ~Map() {
        delete[] layer;
        objectsCollector.erase(objectsCollector.begin(), objectsCollector.end());
    };

    bool load();

    void setViewLimits();

    const sf::Vector2f &getSpawnPoint() const;

    Layer *getLayer() const;

    float getHeight() const;

    float getWidth() const;

    float getViewHorizontalLimitSx() const;

    float getViewHorizontalLimitDx() const;

    float getViewVerticalLimitUp() const;

    float getViewVerticalLimitDown() const;

    const float getAcceleration() const;

    const float getWaterAcceleration() const;

//    std::vector<std::unique_ptr<Item>> &getObjectsCollector();
    std::vector<Item *> &getObjectsCollector();

    const float getViewHeight() const;

    const float getViewWidth() const;

    void setSpawnPoint(const sf::Vector2f &spawnPoint);

    std::vector<Item *> &getAnimatedObjects();

    void updateObjects();

    const std::string &getObjects() const;

    bool isEndLevel() const;

    void setEndLevel(bool endLevel);

    int getMapId() const;

    std::vector<Enemy *> &getEnemies();

    void updateEnemies(GameHero &player);

    std::vector<Door *> &getDoors();

private:
    std::string background, ground, objects;

    bool endLevel;

    float height;
    float width;

    sf::Vector2f spawn_point;

    float viewHorizontalLimitSX;
    float viewHorizontalLimitDX;

    float viewVerticalLimitUP;
    float viewVerticalLimitDOWN;

    const float gravity = -0.02f;
    const float waterGravity = -0.005f;

    Layer *layer;

//    std::vector<std::unique_ptr<Item>> objectsCollector;
    std::vector<Item *> objectsCollector;

    std::vector<Item *> movingObjects;

    std::vector<Door *> doors;

    std::vector<Enemy *> enemies;


    const float viewHeight = 300.f;
    const float viewWidth = 500.f;

    int mapID;

};

#endif //_MAP_H