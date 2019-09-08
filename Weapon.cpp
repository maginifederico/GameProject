/**
 * Project Untitled
 */


#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <math.h>
#include "Weapon.h"
#include "GameHero.h"

/**
 * Weapon implementation
 */


Weapon::Weapon(std::string &textPath, float textScale, int dmg, float rng, float cDown, float explRange, int lvl)
        : texturePath(textPath), textureScale(textScale), damage(dmg), range(rng), cooldown(cDown),
          explosionRange(explRange), level(lvl) {}

//
//Weapon::Weapon(Weapon &gun) : texturePath(gun.texturePath), textureScale(gun.textureScale), damage(gun.damage),
//                              range(gun.range), cooldown(gun.cooldown), level(gun.level),
//                              explosionRange(gun.explosionRange) {
//
//}


void Weapon::shoot(Weapon *gun, sf::Vector2f playerPosition, bool movDirection) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > cooldown) {
            gun->projectils.emplace_back(Projectile(gun->texturePath, playerPosition, gun->textureScale, movDirection));
            clock.restart();
        }

    }

    if (!projectils.empty()) {
        for (int i = 0; i < projectils.size(); i++) {

            if ((fabs(projectils[i].getSprite().getPosition().x - projectils[i].getInitialPosition().x) > gun->range)
                || projectils[i].getSprite().getPosition().x > 6300.f
                || projectils[i].getSprite().getPosition().x < 0.f
                ||)
                projectils.erase(projectils.begin() + i);
            else
                projectils[i].updatePosition();
        }
    }

}

std::vector<Projectile> &Weapon::getProjectils() {
    return projectils;
}
