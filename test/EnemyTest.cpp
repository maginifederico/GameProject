//
// Created by sode on 09/10/19.
//

#include <gtest/gtest.h>
#include "../EnemyFactory.h"
#include "../GameHero.h"

TEST (Enemy, EnemyFactory) {

    GameHero hero(sf::Vector2f(105.f, 0.f), sf::Vector2f(800.f, 525.f));

    EnemyFactory enemyFactory;

    Enemy *mole = enemyFactory.createEnemy(38, 21, 0);
    Enemy *shooterDX = enemyFactory.createEnemy(127, 3 * 21, 0);
    Enemy *shooterSX = enemyFactory.createEnemy(128, 2 * 21, 0);
    Enemy *bat = enemyFactory.createEnemy(129, 0, 5 * 21);

    ASSERT_FALSE(dynamic_cast<WalkingBehaviour *>(mole->getMovementBehaviour()) == nullptr);
    ASSERT_FALSE(dynamic_cast<StillBehaviour *>(shooterDX->getMovementBehaviour()) == nullptr);
    ASSERT_FALSE(dynamic_cast<StillBehaviour *>(shooterSX->getMovementBehaviour()) == nullptr);
    ASSERT_FALSE(dynamic_cast<FlyingBehaviour *>(bat->getMovementBehaviour()) == nullptr);
}

TEST(Enemy, Behaviour) {

    EnemyFactory enemyFactory;

    Enemy *mole = enemyFactory.createEnemy(38, 100.f, 336.6f);
    Enemy *shooterDX = enemyFactory.createEnemy(127, 100.f, 336.f);
    Enemy *shooterSX = enemyFactory.createEnemy(128, 100.f, 336.f);
    Enemy *bat = enemyFactory.createEnemy(129, 21.f, 5 * 21.f);

    GameHero hero(sf::Vector2f(105.f, 0.f), sf::Vector2f(800.f, 525.f));

    Map map(6300.f, 525.f, sf::Vector2f(0, 0), "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt", "objectsLevel1",
            1);
    map.load();

    map.getEnemies().push_back(mole);
    map.getEnemies().push_back(shooterDX);
    map.getEnemies().push_back(shooterSX);
    map.getEnemies().push_back(bat);

    StillBehaviour *ptrDX = dynamic_cast<StillBehaviour *>(shooterDX->getMovementBehaviour());
    StillBehaviour *ptrSX = dynamic_cast<StillBehaviour *>(shooterSX->getMovementBehaviour());

    ptrDX->setShootingCooldown(0.f);
    ptrSX->setShootingCooldown(0.f);

    mole->updatePosition(map);
    shooterDX->updatePosition(map);
    shooterSX->updatePosition(map);
    bat->updatePosition(map);

//    StillBehaviour *ptrDX = dynamic_cast<StillBehaviour *>(shooterDX);
//    StillBehaviour *ptrSX = dynamic_cast<StillBehaviour *>(shooterSX);
//
//    if (ptrDX != nullptr && ptrSX != nullptr) {
//
//        while (ptrDX->getProjectiles().empty())
//            shooterDX->updatePosition(map);
//
//        while (ptrSX->getProjectiles().empty())
//            shooterSX->updatePosition(map);
//
//    }

    ASSERT_FLOAT_EQ(mole->getSprite().getPosition().x, 21 - mole->getSpeed());
    ASSERT_TRUE(ptrDX->getProjectiles()[0].rightDirection());
    ASSERT_FALSE(ptrSX->getProjectiles()[0].rightDirection());
    ASSERT_FLOAT_EQ(bat->getSprite().getPosition().x, bat->getSpeed());
    ASSERT_FLOAT_EQ(bat->getSprite().getPosition().y, 105.f - bat->getSpeed());


}