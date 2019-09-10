/**
 * Project Untitled
 */


#include <iostream>
#include "Projectile.h"

/**
 * Projectile implementation
 */




void Projectile::damage() {

}

Projectile::Projectile(std::string &texturePath, sf::Vector2f initPosition, float textureScale, bool movDirection)
        : initialPosition(initPosition), direction(movDirection) {

    if (!texture.loadFromFile(texturePath))
        std::cout << "Unable to load the sprite";

    sprite.setTexture(texture);
    sprite.setScale(textureScale, textureScale);

    sprite.setPosition(initPosition.x /*+ player.getSprite().getGlobalBounds().width/2*/,
                       initPosition.y /*+ player.getSprite().getGlobalBounds().height/4*/);


}

sf::Sprite &Projectile::getSprite() {
    return sprite;
}

void Projectile::updatePosition() {

    if (direction)
        sprite.move(speed, 0);
    else
        sprite.move(-speed, 0);
}

const sf::Vector2f &Projectile::getInitialPosition() const {
    return initialPosition;
}

bool Projectile::rightDirection() const {
    return direction;
}
