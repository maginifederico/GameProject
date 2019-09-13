/**
 * Project Untitled
 */


#include "Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


Map::Map(float width, float height, sf::Vector2f sPoint, std::string background,
         std::string ground/*, std::string objects*/)
        : width(width), height(height), spawn_point(sPoint), background(background),
          ground(ground)/*, objects(objects)*/ {
    //crea 3 layer
    layer = new Layer[3]();
}

bool Map::load() {
//    if (!layer[0].load(sf::Vector2u(21, 21), background))
//        return -1;

    if (!layer[1].load(sf::Vector2u(21, 21), ground))
        return -1;

//    if (!layer[3].load(sf::Vector2u(21, 21), objects))
//        return -1;
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

void Map::setViewLimits(float w, float h) {

    viewHorizontalLimitSX = w / 4;
    viewHorizontalLimitDX = Map::width - (w * 3 / 4);

    viewVerticalLimitDOWN = Map::height - h / 2;
    viewVerticalLimitUP = h / 2;

}


//void Map::setLayer(Layer *layer) {
//    Map::layer = layer;
//}

//class Map {
//public:
//    Map(SharedContext *l_context, BaseState *l_currentState);
//
//    ~Map();
//
//    Tile *GetTile(unsigned int l_x, unsigned int l_y);
//
//    TileInfo *GetDefaultTile();
//
//    float GetGravity() const;
//
//    unsigned int GetTileSize() const;
//
//    const sf::Vector2u &GetMapSize() const;
//
//    const sf::Vector2f &GetPlayerStart() const;
//
//    void LoadMap(const std::string &l_path);
//
//    void LoadNext();
//
//    void Update(float l_dT);
//
//    void Draw();

//private:
// Method for converting 2D coordinates to 1D ints.
//    unsigned int ConvertCoords(unsigned int l_x, unsigned int l_y);
//
//    void LoadTiles(const std::string &l_path);
//
//    void PurgeMap();
//
//    void PurgeTileSet();
//
//    TileSet m_tileSet;
//    TileMap m_tileMap;
//    sf::Sprite m_background;
//    TileInfo m_defaultTile;
//    sf::Vector2u m_maxMapSize;
//    sf::Vector2f m_playerStart;
//    unsigned int m_tileCount;
//    unsigned int m_tileSetCount;
//    float m_mapGravity;
//    std::string m_nextMap;
//    bool m_loadNextMap;
//    std::string m_backgroundTexture;
//    BaseState *m_currentState;
//    SharedContext *m_context;
//};




/**
 * Map implementation
 */
