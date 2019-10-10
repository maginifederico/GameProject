//
// Created by federico on 04/07/19.
//

#ifndef GAME_LAYER_H
#define GAME_LAYER_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Tile.h"
#include "Item.h"


class Item;

class Layer : public sf::Drawable, public sf::Transformable {
public:

    explicit Layer(int width = 300, int height = 25, std::string tile_set_path = "./Textures/tilesetC1.png");

    bool load(sf::Vector2u tileSize, std::string &map_path);


//    bool loadObject(sf::Vector2u tileSize, std::string &map_path, std::vector<std::unique_ptr<Item>> objectsCollector);
    bool loadObject(Map *map);

    Tile *getTile() const;

    ~Layer() override {
        delete[] tile;
    };


private:

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    unsigned int height;
    unsigned int width;

    Tile *tile;

    std::string tileset;

};

#endif //GAME_LAYER_H
