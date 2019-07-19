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
    explicit Map(unsigned int width, unsigned int height, std::string background,
                 std::string ground/*, std::string objects*/); // 3 path + h e w

    ~Map() {
        delete[] layer;
    };

    bool load();

    const sf::Vector2f &getSpawnPoint() const;

    Layer *getLayer() const;


private:
public:
    unsigned int getHeight() const;

    unsigned int getWidth() const;

private:
    unsigned int height;
    unsigned int width;
//    float height;
//    float width;
    Layer *layer;


//    void setLayer(Layer *layer);

    std::string background, ground, objects;

    const sf::Vector2f spawn_point = sf::Vector2f(100.f, 0.f);



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