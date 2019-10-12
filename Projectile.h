/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Enemy.h"

class Projectile {
public:

    Projectile(std::string &texturePath, sf::Vector2f initialPosition, float textureScale, Direction movDirection,
               int damage, float speed);

    void updatePosition();

    void inflictDamage(Map &map, GameCharacter *target);

    sf::Sprite &getSprite();

    const sf::Vector2f &getInitialPosition() const;

    Direction getDirection() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;

    sf::Vector2f initialPosition;
    float speed;

    //indica la direzione del proiettile, se è true va verso destra, se è false va verso sinistra
    Direction direction;

    int damage;

};

#endif //_PROJECTILE_H