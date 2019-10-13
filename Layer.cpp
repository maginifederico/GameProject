//
// Created by federico on 07/07/19.
//

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <fstream>
#include "ObjectFactory.h"
#include "Layer.h"
#include "DoorFactory.h"
#include "EnemyFactory.h"


Layer::Layer(int w, int h, std::string tileSet) : width(w), height(h), tileset(tileSet) {
    tile = new Tile[width * height];
}

bool Layer::load(sf::Vector2u tileSize, std::string &map_path) {

    std::ifstream my_file(map_path);

    int layer[width * height];

//Crea factory

    for (int i = 0; i < width * height; i++) {
        my_file >> layer[i];
//           if(layer[i] != 0)

//               Item
//               objectsCollector->push_back(Item());
        tile[i].setId(layer[i]);
    }

    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    //Gestisce lo scorrimento di objectsCollector
    int k = 0;

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j) {
            // get the current tile number
            int tileNumber = tile[i + j * width].getId();

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x); //colonna
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x); //riga

            // get a pointer to the current tile'sprite quad
            sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);                //top left
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);          //top right
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);    //bottom right
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);          //bottom left

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

            //se non e' una tile di aria, imposta la sua collisione, altrimenti togli collision = FloatRect(0, 0, 0, 0)
            if (tile[i + j * width].getId() != 0) {
                tile[i + j * width].setCollision(sf::FloatRect(quad[0].position, sf::Vector2f(tileSize.x, tileSize.y)));
//                objectsCollector[k].
//                k++;
            } else
                tile[i + j * width].setCollision(sf::FloatRect());
        }
    return true;
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
// apply the transform
    states.transform *= getTransform();

// apply the tileset texture
    states.texture = &m_tileset;

// draw the vertex array
    target.draw(m_vertices, states);
}

Tile *Layer::getTile() const {
    return tile;
}

//bool Layer::loadObject(sf::Vector2u tS, std::string &map_path, std::vector<std::unique_ptr<Item>> objectsCollector) {
bool Layer::loadObject(Map *map) {


    std::ifstream my_file(map->getObjects());

    int layer[width * height];

    //Crea factory
    ObjectFactory objectsFactory;
    EnemyFactory enemyFactory;
    DoorFactory doorFactory;


    float posX;
    float posY;

    const int redFlagLow = 134;   //CHECKPOINT
    const int stoneGenerator = 135; //blueFlagLow
    const int blueFlag = 133;
    const int blackDoorID = 56;
    const int brownDoorID = 54;


    for (int i = 0; i < width * height; i++) {
        my_file >> layer[i];
        if (layer[i] != 0) {


            posX = (i % int(map->getWidth() / 21)) * 21.f;
            posY = (i / int(map->getWidth() / 21)) * 21.f;

            sf::FloatRect collision(posX, posY, 21.f, 21.f);
            sf::FloatRect checkpointCollision(posX, 0, 5.f, map->getHeight());
            sf::FloatRect doorCollision(posX, posY, 21.f, 42.f);

//            std::unique_ptr<Item> object = objectsFactory.createObject(layer[i]);
            if (layer[i] == blackDoorID || layer[i] == brownDoorID) {
                Door *door = doorFactory.createDoor(layer[i], map->getMapId(), i % int(map->getWidth() / 21), posX,
                                                    posY);

                if (door != nullptr) {
                    door->getSprite().setPosition(posX, posY);
                    door->setCollision(doorCollision);
                    map->getDoors().push_back(door);
                }

            } else {
                Item *object = objectsFactory.createObject(layer[i], posX, posY);

                if (object != nullptr) {

                    if (layer[i] == redFlagLow || layer[i] == blueFlag)
                        object->setCollision(checkpointCollision);
                    else
                        object->setCollision(collision);

                    if (layer[i] == stoneGenerator || layer[i] == blueFlag) {

                        map->getAnimatedObjects().push_back(object);

                    }


                    map->getObjectsCollector().push_back(object);
                    object->getSprite().setPosition(posX, posY);

                } else {

                    Enemy *enemy = enemyFactory.createEnemy(layer[i], posX, posY);
                    if (enemy != nullptr)
                        map->getEnemies().push_back(enemy);

                }
            }
        }

    }

    return true;
}