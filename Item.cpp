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
