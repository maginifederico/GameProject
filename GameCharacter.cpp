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

int GameCharacter::getHp() const {
    return HP;
}

float GameCharacter::getSpeed() const {
    return speed;
}

GameCharacter::~GameCharacter() = default;