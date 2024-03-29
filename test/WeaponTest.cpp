//
// Created by federico on 17/09/19.
//

#include <cmath>
#include "gtest/gtest.h"
#include "../Weapon.h"
#include "../WeaponFactory.h"
#include "../Map.h"

TEST(Weapon, shoot) {

//    WeaponFactory factory;

//    std::unique_ptr<Weapon> weapon = factory.createWeapon(0);


    std::string weaponSpritePath = "./Textures/justOne.png";
    Weapon weapon(weaponSpritePath, 0.f, 0, 50.f, 0.f);

    weapon.createProjectile(sf::Vector2f(0, 0), right);

    ASSERT_FALSE(weapon.getProjectiles().empty());


}

TEST(Weapon, range) {

    Map map(6300.f, 525.f, sf::Vector2f(0, 0), "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt", "objectsLevel1",
            1);
    map.load();

    std::string weaponSpritePath = "./Textures/justOne.png";
    Weapon weapon(weaponSpritePath, 1.f, 0, 50.f, 0.f);

    weapon.createProjectile(sf::Vector2f(10, 10), right);


    do { weapon.getProjectiles()[0].updatePosition(); }
    while ((fabs(weapon.getProjectiles()[0].getSprite().getPosition().x -
                 weapon.getProjectiles()[0].getInitialPosition().x)) < weapon.getRange());

    weapon.checkProjectileCollision(map);

    ASSERT_TRUE(weapon.getProjectiles().empty());
}