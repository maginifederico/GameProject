/**
 * Project Untitled
 */


#include <iostream>
#include "Item.h"

/**
 * Item implementation
 */



Item::Item(std::string &texturePath, int identifier, bool toDraw) : id(identifier), toBeDrawn(toDraw) {

    if (!texture.loadFromFile(texturePath))
        std::cout << "Unable to load the sprite";
    sprite.setTexture(texture);

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

void Item::setCollision(sf::FloatRect &c) {
    Item::collision = c;
}

int Item::getId() const {
    return id;
}

bool Item::isToBeDrawn() const {
    return toBeDrawn;
}
