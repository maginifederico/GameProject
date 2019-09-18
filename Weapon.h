/**
 * Project Untitled
 */


#ifndef _WEAPON_H
#define _WEAPON_H

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameHero.h"
#include "Projectile.h"

class Weapon {
public:

    Weapon(std::string &texturePath, float textureScale, int damage, float range, float cooldown,
           float explosionRange = 0, int level = 1);

//    Weapon(Weapon &gun);

    void shoot(sf::Vector2f playerPosition, bool movementDirection);

    std::vector<Projectile> &getProjectils();

    void checkProjectileCollision(Layer &ground);

private:

    sf::Clock clock;
    std::string texturePath;
    std::vector<Projectile> projectils;

    float textureScale;
    int damage;
    float range;
    float cooldown;
    int level;
    float explosionRange;

    sf::Texture texture;

};

#endif //_WEAPON_H