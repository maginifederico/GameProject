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
#include "ObjectsFactory.h"
#include "Layer.h"


Layer::Layer(int width, int height, std::string tileSet) : width(width), height(height), tileset(tileSet) {
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
bool Layer::loadObject(float mapWidth, std::string &map_path, std::vector<Item *> &objectsCollector) {


    std::ifstream my_file(map_path);

    int layer[width * height];

    //Crea factory
    ObjectFactory objectsFactory;

    float posX;
    float posY;

    for (int i = 0; i < width * height; i++) {
        my_file >> layer[i];
        if (layer[i] != 0) {

//            std::unique_ptr<Item> object = objectsFactory.createObject(layer[i]);
            Item *object = objectsFactory.createObject(layer[i]);

            if (object != nullptr) {

                posX = (i % int(mapWidth / 21)) * 21.f;
                posY = (i / int(mapWidth / 21)) * 21.f;

                sf::FloatRect collision(posX, posY, 21.f, 21.f);
                object->setCollision(collision);

                object->getSprite().setPosition(posX, posY);
                objectsCollector.push_back(object);
            }
        }

    }

}