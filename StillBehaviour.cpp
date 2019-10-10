//
// Created by federico on 03/10/19.
//

#include "StillBehaviour.h"
#include "Map.h"
#include "math.h"


StillBehaviour::StillBehaviour(Direction dir) {

    direction = dir;

    float shootingCooldown = 1.f;
    float projectileScale = 0.5f;
    float projectileSpeed = 2.f;
    float projectileRange = 500.f;
    int projectileDamage = 20;
    std::string projectilePath = "./Textures/StillEnemyProjectile.png";

    weapon = new Weapon(projectilePath, projectileScale, projectileDamage, projectileRange, shootingCooldown);

}

void StillBehaviour::updatePosition(Map &map, Enemy &enemy) {


    weapon->createProjectile(enemy.getSprite().getPosition(), direction);

    weapon->checkProjectileCollision(map, player);

}

void StillBehaviour::attack() {

}


void StillBehaviour::setPlayer(GameHero *hero) {
    StillBehaviour::player = hero;
}

StillBehaviour::~StillBehaviour() {

    delete weapon;

}

Weapon *StillBehaviour::getWeapon() const {
    return weapon;
}
