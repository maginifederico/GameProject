//
// Created by federico on 02/10/19.
//

#ifndef GAME_ENEMYFACTORY_H
#define GAME_ENEMYFACTORY_H


#include "Enemy.h"

class EnemyFactory {

public:
    Enemy *createEnemy(int id, float posX, float posY);

};

Enemy *EnemyFactory::createEnemy(int id, float posX, float posY) {

    Enemy *result;

    const int mole = 38;
    const int shooterDX = 127;
    const int shooterSX = 128;
    const int fly = 129;

    switch (id) {

        case mole: {

            std::string moleTexturePath = "./Textures/MoleGroundEnemySX.png";
            float moleSpeed = 0.5f;
            float moleUnderWaterSpeed = 0.5f;
            int HP = 70;

            result = new Enemy(moleTexturePath, sf::Vector2f(posX, posY), moleSpeed, moleUnderWaterSpeed, HP, id);

            break;
        }

        case shooterDX:
        case shooterSX: {

            std::string shooterTexturePath;

            if (id == shooterDX)
                shooterTexturePath = "./Textures/ShootingEnemyDX.png";

            if (id == shooterSX)
                shooterTexturePath = "./Textures/ShootingEnemySX.png";


            float shooterSpeed = 0.5f;
            float shooterUnderWaterSpeed = 0.5f;
            int HP = 50;

            result = new Enemy(shooterTexturePath, sf::Vector2f(posX, posY), shooterSpeed, shooterUnderWaterSpeed, HP,
                               id);

            break;
        }

        case fly: {

            std::string flyTexturePath = "./Textures/FlyingEnemySX1.png";
            float flySpeed = 0.5f;
            float flyUnderWaterSpeed = 0.5f;
            int HP = 30;

            result = new Enemy(flyTexturePath, sf::Vector2f(posX, posY), flySpeed, flyUnderWaterSpeed, HP, id);

            break;
        }


        default:
            result = nullptr;

    }

    return result;
}


#endif //GAME_ENEMYFACTORY_H
