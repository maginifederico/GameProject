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


class Layer : public sf::Drawable, public sf::Transformable {
public:

    explicit Layer(int width = 300, int height = 25, std::string tile_set_path = "./Textures/tileSetC.png");

    bool load(sf::Vector2u tileSize, std::string map_path);

    Tile *getTile() const;

    ~Layer() override {
        delete[] tile;
    };


    //const sf::Vector2f &Layer::getSpawnPoint() const;

private:

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    unsigned int height;
    unsigned int width;


    Tile *tile;
    //const sf::Vector2f spawn_point = sf::Vector2f(100.f, 0.f);


    std::string tileset;

};

#endif //GAME_LAYER_H
