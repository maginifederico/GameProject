/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

#include "GameCharacter.h"
#include "Item.h"
#include "Layer.h"

class Map {
public:
    explicit Map(float width, float height, sf::Vector2f spawnPoint, std::string background, std::string ground,
                 std::string objects);

    ~Map() {
        delete[] layer;
        objectsCollector.erase(objectsCollector.begin(), objectsCollector.end());
    };

    bool load();

    void setViewLimits(float width, float height);

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

private:
    std::string background, ground, objects;

    float height;
    float width;

    const sf::Vector2f spawn_point;

    float viewHorizontalLimitSX;
    float viewHorizontalLimitDX;

    float viewVerticalLimitUP;
    float viewVerticalLimitDOWN;

    const float gravity = -0.02f;
    const float waterGravity = -0.005f;

    Layer *layer;

//    std::vector<std::unique_ptr<Item>> objectsCollector;
    std::vector<Item *> objectsCollector;


//    Item *item[];



//    Obstacle *obstacle[];
//    GameCharacter *GameCharacter[];
};

//Map::Map(SharedContext *l_context, BaseState *l_currentState)
//        : m_context(l_context), m_defaultTile(l_context),
//          m_maxMapSize(32, 32), m_tileCount(0), m_tileSetCount(0),
//          m_mapGravity(512.f), m_loadNextMap(false),
//          m_currentState(l_currentState) {
//    m_context->m_gameMap = this;
//    LoadTiles("tiles.cfg");
//}

#endif //_MAP_H