//
// Created by federico on 03/10/19.
//

#include "StillBehaviour.h"
#include "Map.h"
#include "math.h"


StillBehaviour::StillBehaviour() {

    if (!projectileTexture.loadFromFile(projectilePath))
        std::cout << "Unable to load the sprite";
}

void StillBehaviour::updatePosition(Map &map, Enemy &enemy) {

//    for (int i = 0; i < projectiles.size(); i++)
//        projectiles[i].updatePosition();

    if (!projectiles.empty())
        checkProjectileCollision(map);

    if (shootingClock.getElapsedTime().asSeconds() > shootingCooldown) {
        createProjectile(enemy);
        shootingClock.restart();
    }

}

void StillBehaviour::attack() {

}

void StillBehaviour::createProjectile(Enemy &enemy) {

    rightDirection = enemy.getId() == shooterDX;


    Projectile newProjectile(projectilePath, enemy.getSprite().getPosition(), projectileScale, rightDirection,
                             enemy.getMeleeDamage(), projectileSpeed);

    newProjectile.getSprite().setTexture(projectileTexture);

    projectiles.emplace_back(newProjectile);


}

const std::vector<Projectile> &StillBehaviour::getProjectiles() const {
    return projectiles;
}

void StillBehaviour::checkProjectileCollision(Map &map) {


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


            if (projectiles[i].rightDirection()) {

                //GROUND COLLISION
                if (
                        (projectiles[i].getSprite().getPosition().x + projectileWidth >= map.getWidth()
                         || projectiles[i].getSprite().getGlobalBounds().intersects(rightCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(rightDownCollision))
                        && (rightID != water && rightID != waterSurface && downRightID != waterSurface)

                        )
                    collision = true;
                else
                    collision = false;

                //ENEMY COLLISION


                //// SCRIVERE QUI LA COLLISIONE COL PLAYER. SERVE UN RIFERIMENTO AL PLAYER
                for (int y = 0; y < map.getEnemies().size(); y++) {
                    if (projectiles[i].getSprite().getGlobalBounds().intersects(
                            player->getSprite().getGlobalBounds())) {
                        projectiles[i].inflictDamage(map, player);
                        projectiles.erase(projectiles.begin() + i);
                        return;
                    }
                }


            } else {
                if (
                        (projectiles[i].getSprite().getPosition().x <= 0.f
                         || projectiles[i].getSprite().getGlobalBounds().intersects(leftCollision)
                         || projectiles[i].getSprite().getGlobalBounds().intersects(leftDownCollision))
                        && (leftID != water && leftID != waterSurface && downLeftID != waterSurface)

                        )
                    collision = true;
                else
                    collision = false;

                //// SCRIVERE QUI LA COLLISIONE COL PLAYER. SERVE UN RIFERIMENTO AL PLAYER
                for (int y = 0; y < map.getEnemies().size(); y++) {
                    if (projectiles[i].getSprite().getGlobalBounds().intersects(
                            player->getSprite().getGlobalBounds())) {
                        projectiles[i].inflictDamage(map, player);
                        projectiles.erase(projectiles.begin() + i);
                        return;
                    }
                }
            }


            if ((fabs(projectiles[i].getSprite().getPosition().x - projectiles[i].getInitialPosition().x) >
                 projectileRange)
                || collision
                    )
                projectiles.erase(projectiles.begin() + i);
            else
                projectiles[i].updatePosition();
        }
    }
}

void StillBehaviour::setShootingCooldown(float shootingCooldown) {
    StillBehaviour::shootingCooldown = shootingCooldown;
}

void StillBehaviour::setPlayer(GameHero *player) {
    StillBehaviour::player = player;
}
