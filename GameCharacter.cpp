/**
 * GameCharacter implementation
 */

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"


GameCharacter::GameCharacter(std::string texture, sf::Vector2f initialPosition, float mov_speed) {
    if (!this->texture.loadFromFile(texture))
        std::cout << "Unable to load the sprite";
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(initialPosition);
    speed = mov_speed;
}

const sf::Sprite &GameCharacter::getSprite() const {
    return sprite;
}

const sf::Texture &GameCharacter::getTexture() const {
    return texture;
}

void GameCharacter::setTexture(const sf::Texture &texture) {
    GameCharacter::texture = texture;
}
