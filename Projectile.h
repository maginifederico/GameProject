/**
 * Project Untitled
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Projectile {
public:

    Projectile(std::string &texturePath, sf::Vector2f initialPosition, float textureScale, bool movDirection,
               int damage);

    void updatePosition();

    void inflictDamage();

    sf::Sprite &getSprite();

    const sf::Vector2f &getInitialPosition() const;

    bool rightDirection() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;

    sf::Vector2f initialPosition;
    float speed = 3.f;

    //indica la direzione del proiettile, se è true va verso destra, se è false va verso sinistra
    bool direction;

    int damage;

};

#endif //_PROJECTILE_H