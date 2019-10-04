/**
 * Project Untitled
 */


#include <iostream>
#include "Projectile.h"

/**
 * Projectile implementation
 */




void Projectile::inflictDamage() {

}

Projectile::Projectile(std::string &texturePath, sf::Vector2f initPosition, float textureScale, bool movDirection,
                       int damage)
        : initialPosition(initPosition), direction(movDirection), damage(damage) {

    sprite.setScale(textureScale, textureScale);

    sprite.setPosition(initPosition.x, initPosition.y);


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
