/**
 * Project Untitled
 */


#include "Enemy.h"

/**
 * Enemy implementation
 */


//void Enemy::attack() {
//
//}

Enemy::Enemy(std::string &texturePath, sf::Vector2f position, float speed, float uWspeed, int hp,
             int id, MovementBehaviour *behaviour, int melee) : GameCharacter(texturePath, position, speed,
                                                                              uWspeed, hp), id(id), meleeDamage(melee) {

    const int mole = 38;
    const int shooterDX = 127;
    const int shooterSX = 128;
    const int fly = 129;

    if (id == mole) {
        sprite.setScale(sf::Vector2f(0.466666667, 0.7));
        sprite.scale(0.15f, 0.15f);
    }

    if (id == fly) {
        sprite.scale(0.5f, 0.5f);
    }

    movementBehaviour = behaviour;

}

void Enemy::setHP(int hp, Map &map) {
    HP = hp;
}

int Enemy::getMeleeDamage() const {
    return meleeDamage;
}

MovementBehaviour *Enemy::getMovementBehaviour() const {
    return movementBehaviour;
}

int Enemy::getId() const {
    return id;
}
