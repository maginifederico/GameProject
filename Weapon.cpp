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


        //Gestione cooldown
        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > cooldown) {
            gun->projectils.emplace_back(Projectile(gun->texturePath, playerPosition, gun->textureScale, movDirection));
            clock.restart();
        }

    }
//
//    //Se ci sono proiettili sulla mappa, aggiorna la posizione, o cancellali
//    if (!projectils.empty()) {
//        for (int i = 0; i < projectils.size(); i++) {
//
//            if (
//                    (fabs(projectils[i].getSprite().getPosition().x - projectils[i].getInitialPosition().x) >
//                     gun->range)
//                    || projectils[i].getSprite().getPosition().x > 6300.f
//                    || projectils[i].getSprite().getPosition().x < 0.f
////                    || layer
//                // oppure se collide con layer ground
//                    )
//                projectils.erase(projectils.begin() + i);
//            else
//                projectils[i].updatePosition();
//        }
//    }

}

std::vector<Projectile> &Weapon::getProjectils() {
    return projectils;
}

void Weapon::projectileCollision(Layer &ground) {

    int c;
    int r;

    int sinistra;
    int destra;

    bool collision;

    float projectileWidth;

    //Se ci sono proiettili sulla mappa, aggiorna la posizione, o cancellali
    if (!projectils.empty()) {
        projectileWidth = projectils[0].getSprite().getGlobalBounds().width;
        for (int i = 0; i < projectils.size(); i++) {

            c = (int) projectils[i].getSprite().getPosition().x / 21;
            r = (int) projectils[i].getSprite().getPosition().y / 21;

            sinistra = ground.getTile()[c + r * 300].getId();
            destra = ground.getTile()[c + r * 300 + 1].getId();

            if (projectils[i].rightDirection())
                if (
                        projectils[i].getSprite().getPosition().x + projectileWidth > 6300.f
                        || (destra != 0 && destra != 47 && destra != 48)

                        )
                    collision = true;
                else
                    collision = false;
            else {
                if (
                        projectils[i].getSprite().getPosition().x < 0.f
                        || (sinistra != 0 && sinistra != 47 && sinistra != 48)
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
