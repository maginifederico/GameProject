/**
 * Project Untitled
 */


#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <math.h>
#include "Weapon.h"
#include "GameHero.h"
#include "Map.h"
#include "Bonus.h"

/**
 * Weapon implementation
 */


Weapon::Weapon(std::string &textPath, float textScale, int dmg, float rng, float cDown, float explRange, int lvl)
        : texturePath(textPath), textureScale(textScale), damage(dmg), range(rng), cooldown(cDown),
          explosionRange(explRange), level(lvl) {

//    std::string pippo = "./Textures/Transparent.png";
//    attackBonus = new Bonus(pippo, 0, 0.f, 0);
    attackBonus = nullptr;
    if (!texture.loadFromFile(textPath))
        std::cout << "Unable to load the sprite";
}

//
//Weapon::Weapon(Weapon &gun) : texturePath(gun.texturePath), textureScale(gun.textureScale), inflictDamage(gun.setHP),
//                              range(gun.range), cooldown(gun.cooldown), level(gun.level),
//                              explosionRange(gun.explosionRange) {
//
//}


void Weapon::createProjectile(sf::Vector2f playerPosition, bool movementDirection) {

    //Gestione cooldown
    sf::Time elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() > cooldown) {
        int bonus;
        if (attackBonus == nullptr) {
            bonus = 0;
        } else {
            bonus = damage * attackBonus->getBonusValue() / 100;
        }
        Projectile newProjectile(
                Projectile(texturePath, playerPosition, textureScale, movementDirection, damage + bonus));
        newProjectile.getSprite().setTexture(texture);
        projectiles.emplace_back(newProjectile);
        clock.restart();
    }

}

std::vector<Projectile> &Weapon::getProjectiles() {
    return projectiles;
}

void Weapon::checkProjectileCollision(Map &map) {


    int c;
    int r;

    int leftID;
    int rightID;
    int downLeftID;
    int downRightID;

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
            //per ogni proiettile nel vettore projectiles

            //posizione del proiettile nella matrice del layer ground
            c = (int) projectiles[i].getSprite().getPosition().x / 21;
            r = (int) projectiles[i].getSprite().getPosition().y / 21;

            //ID dei tile adiacenti al proiettile
            leftID = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21)].getId();
            rightID = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1].getId();
            downLeftID = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) +
                                                     int(map.getWidth() / 21)].getId();
            downRightID = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1 +
                                                      int(map.getWidth() / 21)].getId();


            //Rettangoli di collisione dei 4 tile che contengono il proiettile
            //(i tile di aria non hanno collisione)
            leftCollision = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21)].getCollision();
            rightCollision = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1].getCollision();
            leftDownCollision = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) +
                                                            int(map.getWidth() / 21)].getCollision();
            rightDownCollision = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1 +
                                                             int(map.getWidth() / 21)].getCollision();


            if (projectiles[i].rightDirection())
                if (
                        (projectiles[i].getSprite().getPosition().x + projectileWidth >= map.getWidth()
                         || projectiles[i].getSprite().getGlobalBounds().intersects(rightCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(rightDownCollision))
                        && (rightID != water && rightID != waterSurface && downRightID != waterSurface)

                        )
                    collision = true;
                else
                    collision = false;
            else {
                if (
                        (projectiles[i].getSprite().getPosition().x <= 0.f
                         || projectiles[i].getSprite().getGlobalBounds().intersects(leftCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(leftDownCollision))
                        && (leftID != water && leftID != waterSurface && downLeftID != waterSurface)

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

Bonus *Weapon::getAttackBonus() {
    return attackBonus;
}

void Weapon::setAttackBonus(Bonus *aB) {
    Weapon::attackBonus = aB;
}
