//
// Created by federico on 07/07/19.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

#include <SFML/Graphics/Texture.hpp>
#include "Collision.h"

class Tile {
public:

    int getId() const;

    void setId(int id);

    sf::FloatRect &getCollision();

    void setCollision(const sf::FloatRect &collision);

private:
    int id;
    sf::FloatRect collision;
};

#endif //GAME_TILE_H
