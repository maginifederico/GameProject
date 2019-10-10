/**
 * Project Untitled
 */


#include <iostream>
#include "Projectile.h"
#include "GameHero.h"

/**
 * Projectile implementation
 */




void Projectile::inflictDamage(Map &map, GameCharacter *target) {

    Enemy *enemy = dynamic_cast<Enemy *>(target);
    GameHero *hero = dynamic_cast<GameHero *>(target);

    if (enemy != nullptr) {

        enemy->setHP(enemy->getHp() - damage, map);

        if (enemy->getHp() <= 0) {
            for (int i = 0; i < map.getEnemies().size(); i++) {
                if (map.getEnemies()[i] == enemy)
                    map.getEnemies().erase(map.getEnemies().begin() + i);
            }
        }
    }

    if (hero != nullptr) {

        hero->setHP(hero->getHp() - damage, map);

    }

}

Projectile::Projectile(std::string &texturePath, sf::Vector2f initPosition, float textureScale,
                       enum Direction movDirection,
                       int dmg, float sp) : initialPosition(initPosition), direction(movDirection), damage(dmg) {

    speed = sp;

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

Direction Projectile::getDirection() const {
    return direction;
}
