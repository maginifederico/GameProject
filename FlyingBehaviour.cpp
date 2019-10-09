/**
 * Project Untitled
 */


#include "FlyingBehaviour.h"
#include "Enemy.h"

/**
 * FlyingBehaviour implementation
 */

FlyingBehaviour::FlyingBehaviour(bool dir) {

    rightDirection = dir;

    std::string bat = "./Textures/Bat";
    std::string SX = "SX.png";
    std::string DX = "DX.png";

    for (int i = 0; i < 4; i++) {
        animationSX[i] = bat + std::to_string(i + 1) + SX;


        if (!textureSX[i].loadFromFile(animationSX[i]))
            std::cout << "Unable to load the sprite";

        animationDX[i] = bat + std::to_string(i + 1) + DX;

        if (!textureDX[i].loadFromFile(animationDX[i]))
            std::cout << "Unable to load the sprite";
    }

    animationNumber = 0;
}

void FlyingBehaviour::updatePosition(Map &map, Enemy &enemy) {

    if (animationClock.getElapsedTime().asSeconds() > animationTime) {
        if (rightDirection) {
            if (animationNumber == 3) {
                enemy.getSprite().setTexture(textureDX[0]);
                animationNumber = 0;
            } else
                enemy.getSprite().setTexture(textureDX[++animationNumber]);
        } else {
            if (animationNumber == 3) {
                enemy.getSprite().setTexture(textureSX[0]);
                animationNumber = 0;
            } else
                enemy.getSprite().setTexture(textureSX[++animationNumber]);
        }

        animationClock.restart();
    }

    if (playerPosition.x - enemy.getSprite().getPosition().x < 0) {
        enemy.getSprite().move(-enemy.getSpeed(), 0);
        rightDirection = false;
    } else {
        enemy.getSprite().move(enemy.getSpeed(), 0);
        rightDirection = true;
    }

    if (playerPosition.y - enemy.getSprite().getPosition().y > 0)
        enemy.getSprite().move(0, enemy.getSpeed());
    else
        enemy.getSprite().move(0, -enemy.getSpeed());

//
//    if (animationNumber == 2) {
//        if (rightDirection)
//            enemy.getSprite().setTexture(textureDX[0]);
//        else
//            enemy.getSprite().setTexture(textureSX[0]);
//        animationNumber = 0;
//    } else {
//        if (rightDirection)
//            enemy.getSprite().setTexture(textureDX[animationNumber++]);
//        else
//            enemy.getSprite().setTexture(textureDX[animationNumber++]);
//        animationNumber++;
//    }

//    if()

}

void FlyingBehaviour::attack() {

}

void FlyingBehaviour::setPlayerPosition(const sf::Vector2f &playerPos) {
    FlyingBehaviour::playerPosition = playerPos;
}