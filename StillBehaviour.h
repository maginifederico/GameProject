//
// Created by federico on 03/10/19.
//

#ifndef GAME_STILLBEHAVIOUR_H
#define GAME_STILLBEHAVIOUR_H


#include "MovementBehaviour.h"
#include "Projectile.h"
#include "GameHero.h"

class StillBehaviour : public MovementBehaviour {

public:
    StillBehaviour();

    void updatePosition(Map &map, Enemy &enemy) override;

    void attack() override;

    const std::vector<Projectile> &getProjectiles() const;

    void checkProjectileCollision(Map &map);

    void setPlayer(GameHero *player);

    void setShootingCooldown(float shootingCooldown);

private:

    void createProjectile(Enemy &enemy);

    sf::Clock shootingClock;
    sf::Texture projectileTexture;

    float shootingCooldown = 1.f;
    float projectileScale = 0.5f;
    float projectileSpeed = 2.f;
    float projectileRange = 500.f;

    std::string projectilePath = "./Textures/StillEnemyProjectile.png";

    std::vector<Projectile> projectiles;

    const int shooterDX = 127;
    const int shooterSX = 128;

    GameHero *player;
};


#endif //GAME_STILLBEHAVIOUR_H
