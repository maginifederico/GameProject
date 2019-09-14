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
    explicit Map(float width, float height, sf::Vector2f spawnPoint, std::string background,
                 std::string ground/*, std::string objects*/); // 3 path + h e w

    ~Map() {
        delete[] layer;
    };

    bool load();

    const sf::Vector2f &getSpawnPoint() const;

    Layer *getLayer() const;

    float getHeight() const;

    float getWidth() const;

    float getViewHorizontalLimitSx() const;

    float getViewHorizontalLimitDx() const;

    float getViewVerticalLimitUp() const;

    float getViewVerticalLimitDown() const;

    void setViewLimits(float width, float height);

    const float getAcceleration() const;

    const float getWaterAcceleration() const;

private:
    std::string background, ground, objects;

    float height;
    float width;

    const sf::Vector2f spawn_point;

    float viewHorizontalLimitSX = 200.f;
    float viewHorizontalLimitDX = 5700.f;

    float viewVerticalLimitUP = 0.f;
    float viewVerticalLimitDOWN = 525.f;

    const float acceleration = -0.02f;
    const float waterAcceleration = -0.005f;

    Layer *layer;

//    void setLayer(Layer *layer);



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