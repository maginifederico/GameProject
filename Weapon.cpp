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
          explosionRange(explRange), level(lvl) {

    if (!texture.loadFromFile(textPath))
        std::cout << "Unable to load the sprite";
}

//
//Weapon::Weapon(Weapon &gun) : texturePath(gun.texturePath), textureScale(gun.textureScale), damage(gun.damage),
//                              range(gun.range), cooldown(gun.cooldown), level(gun.level),
//                              explosionRange(gun.explosionRange) {
//
//}


void Weapon::shoot(Weapon *gun, sf::Vector2f playerPosition, bool movDirection) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {


        //Gestione cooldown
        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > cooldown) {
            Projectile newProjectile(Projectile(gun->texturePath, playerPosition, gun->textureScale, movDirection));
            newProjectile.getSprite().setTexture(texture);
            gun->projectils.emplace_back(newProjectile);
            clock.restart();
        }

    }

}

std::vector<Projectile> &Weapon::getProjectils() {
    return projectils;
}

void Weapon::checkProjectileCollision(Layer &ground) {

    int c;
    int r;

    int sinistra;
    int destra;

    bool collision;

    int water = 48;
    int waterSurface = 49;

    sf::FloatRect rightCollision;
    sf::FloatRect leftCollision;


    float projectileWidth;

    //Se ci sono proiettili sulla mappa, aggiorna la posizione, o cancellali
    if (!projectils.empty()) {
        projectileWidth = projectils[0].getSprite().getGlobalBounds().width;
        for (int i = 0; i < projectils.size(); i++) {

            c = (int) projectils[i].getSprite().getPosition().x / 21;
            r = (int) projectils[i].getSprite().getPosition().y / 21;

            leftCollision = ground.getTile()[c + r * 300].getCollision();
            leftCollision = ground.getTile()[c + r * 300 + 1].getCollision();

            if (projectils[i].rightDirection())
                if (
//                        projectils[i].getSprite().getPosition().x + projectileWidth > 6300.f
//                        || (destra != 0 && destra != water && destra != waterSurface)

                        projectils[i].getSprite().getGlobalBounds().intersects(rightCollision)

                        )
                    collision = true;
                else
                    collision = false;
            else {
                if (
//                        projectils[i].getSprite().getPosition().x < 0.f
//                        || (sinistra != 0 && sinistra != water && sinistra != waterSurface)

                        projectils[i].getSprite().getGlobalBounds().intersects(leftCollision)

                        )
                    collision = true;
                else
                    collision = false;
            }


            if ((fabs(projectils[i].getSprite().getPosition().x - projectils[i].getInitialPosition().x) > range)
                || collision
                    )
                projectils.erase(projectils.begin() + i);
            else
                projectils[i].updatePosition();
        }
    }

}
