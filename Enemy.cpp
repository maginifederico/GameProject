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
Enemy::Enemy(std::string &moleTexturePath, sf::Vector2f position, float moleSpeed, float moleUnderWaterSpeed, int HP,
             int id, MovementBehaviour *behaviour) : GameCharacter(moleTexturePath, position, moleSpeed,
                                                                   moleUnderWaterSpeed, HP), id(id) {

    const int mole = 38;
    const int shooterDX = 127;
    const int shooterSX = 128;
    const int fly = 129;

    if (id == mole) {
        sprite.setScale(sf::Vector2f(0.466666667, 0.7));
        sprite.scale(0.15f, 0.15f);
    }

    movementBehaviour = behaviour;

}
