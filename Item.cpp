/**
 * Project Untitled
 */


#include <iostream>
#include "Item.h"

/**
 * Item implementation
 */



Item::Item(std::string &texturePath, int identifier) {

    if (!texture.loadFromFile(texturePath))
        std::cout << "Unable to load the sprite";
    sprite.setTexture(texture);

    id = identifier;

}

sf::Sprite &Item::getSprite() {
    return sprite;
}

sf::Texture &Item::getTexture() {
    return texture;
}

const sf::FloatRect &Item::getCollision() const {
    return collision;
}

void Item::setCollision(sf::FloatRect &collision) {
    Item::collision = collision;
}
