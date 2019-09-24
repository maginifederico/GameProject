/**
 * GameCharacter implementation
 */

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"


GameCharacter::GameCharacter(std::string &texture, sf::Vector2f initialPosition, float movSpeed, float movSpeedUW,
                             int hitPoints) : speed(movSpeed), underWaterSpeed(movSpeedUW), HP(hitPoints) {
    if (!this->texture.loadFromFile(texture))
        std::cout << "Unable to load the sprite";
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(initialPosition);
}

sf::Sprite &GameCharacter::getSprite() {
    return sprite;
}

GameCharacter::~GameCharacter() = default;

void GameCharacter::takeDamage(int damage, Map *map) {

    if (HP > damage)
        HP -= damage;

    else
        die(map);
}
