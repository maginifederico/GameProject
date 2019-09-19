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


void Weapon::createProjectile(sf::Vector2f playerPosition, bool movementDirection) {

        //Gestione cooldown
        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > cooldown) {
            Projectile newProjectile(Projectile(texturePath, playerPosition, textureScale, movementDirection));
            newProjectile.getSprite().setTexture(texture);
            projectiles.emplace_back(newProjectile);
            clock.restart();
        }

}

std::vector<Projectile> &Weapon::getProjectiles() {
    return projectiles;
}

void Weapon::checkProjectileCollision(Layer &ground) {

    int c;
    int r;

    int leftID;
    int rightID;

    bool collision;

    int water = 48;
    int waterSurface = 49;


    float projectileWidth;

    sf::FloatRect leftCollision;
    sf::FloatRect leftDownCollision;
    sf::FloatRect rightCollision;
    sf::FloatRect rightDownCollision;

    //Se ci sono proiettili sulla mappa, aggiorna la posizione, o cancellali
    if (!projectiles.empty()) {
        projectileWidth = projectiles[0].getSprite().getGlobalBounds().width;
        for (int i = 0; i < projectiles.size(); i++) {

            c = (int) projectiles[i].getSprite().getPosition().x / 21;
            r = (int) projectiles[i].getSprite().getPosition().y / 21;

            leftID = ground.getTile()[c + r * 300].getId();
            rightID = ground.getTile()[c + r * 300 + 1].getId();


            leftCollision = ground.getTile()[c + r * 300].getCollision();
            rightCollision = ground.getTile()[c + r * 300 + 1].getCollision();
            leftDownCollision = ground.getTile()[c + r * 300 + 300].getCollision();
            rightDownCollision = ground.getTile()[c + r * 300 + 1 + 300].getCollision();


            if (projectiles[i].rightDirection())
                if (
//                        projectiles[i].getSprite().getPosition().x + projectileWidth > 6300.f
//                        || (rightID != 0 && rightID != water && rightID != waterSurface)
                        (projectiles[i].getSprite().getGlobalBounds().intersects(rightCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(rightDownCollision))
                        && rightID != water && rightID != waterSurface

                        )
                    collision = true;
                else
                    collision = false;
            else {
                if (
//                        projectiles[i].getSprite().getPosition().x < 0.f
//                        || (leftID != 0 && leftID != water && leftID != waterSurface)
                        (projectiles[i].getSprite().getGlobalBounds().intersects(leftCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(leftDownCollision))
                        && leftID != water && leftID != waterSurface

                        )
                    collision = true;
                else
                    collision = false;
            }


            if ((fabs(projectiles[i].getSprite().getPosition().x - projectiles[i].getInitialPosition().x) > range)
                || collision
                    )
                projectiles.erase(projectiles.begin() + i);
            else
                projectiles[i].updatePosition();
        }
    }

}
