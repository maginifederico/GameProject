//
// Created by federico on 17/09/19.
//

#include "gtest/gtest.h"
#include "../Weapon.h"
#include "../WeaponFactory.h"

TEST(Weapon, shoot){

    WeaponFactory factory;

    std::unique_ptr<Weapon> weapon = factory.createWeapon(0);

    weapon->shoot(sf::Vector2f(0, 0), true);



}