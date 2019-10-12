//
// Created by federico on 10/10/19.
//

#include "EnemyFactory.h"

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
            int melee = 40;

            result = new Enemy(moleTexturePath, sf::Vector2f(posX, posY), moleSpeed, moleUnderWaterSpeed, HP, id,
                               new WalkingBehaviour(), melee);

            break;
        }

        case shooterDX:

        case shooterSX: {

            std::string shooterTexturePath;

            float shooterSpeed = 0.5f;
            float shooterUnderWaterSpeed = 0.5f;
            int HP = 50;
            int melee = 20;

            if (id == shooterDX) {
                shooterTexturePath = "./Textures/ShootingEnemyDX.png";

                result = new Enemy(shooterTexturePath, sf::Vector2f(posX, posY), shooterSpeed, shooterUnderWaterSpeed,
                                   HP, id, new StillBehaviour(right), melee);
            } else {
                shooterTexturePath = "./Textures/ShootingEnemySX.png";

                result = new Enemy(shooterTexturePath, sf::Vector2f(posX, posY), shooterSpeed, shooterUnderWaterSpeed,
                                   HP, id, new StillBehaviour(left), melee);
            }


            break;
        }

        case fly: {

            std::string flyTexturePath = "./Textures/Bat1SX.png";
            float flySpeed = 0.5f;
            float flyUnderWaterSpeed = 0.5f;
            int HP = 30;
            int melee = 30;

            result = new Enemy(flyTexturePath, sf::Vector2f(posX, posY), flySpeed, flyUnderWaterSpeed, HP, id,
                               new FlyingBehaviour(), melee);

            break;
        }


        default:
            result = nullptr;

    }

    return result;
}