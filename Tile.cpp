//
// Created by federico on 07/07/19.
//

#include "Tile.h"

int Tile::getId() const {
    return id;
}

void Tile::setId(int id) {
    Tile::id = id;
}

sf::FloatRect &Tile::getCollision() {
    return collision;
}

void Tile::setCollision(const sf::FloatRect &collision) {
    Tile::collision = collision;
}
