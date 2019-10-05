/**
 * Project Untitled
 */


#include <iostream>
#include "Projectile.h"

/**
 * Projectile implementation
 */




void Projectile::inflictDamage(Map &map, Enemy *enemy) {

    enemy->setHP(enemy->getHp() - damage, map);

    if (enemy->getHp() <= 0) {
        for (int i = 0; i < map.getEnemies().size(); i++) {
            if (map.getEnemies()[i] == enemy)
                map.getEnemies().erase(map.getEnemies().begin() + i);
        }
    }

}

Projectile::Projectile(std::string &texturePath, sf::Vector2f initPosition, float textureScale, bool movDirection,
                       int dmg) : initialPosition(initPosition), direction(movDirection), damage(dmg) {

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
