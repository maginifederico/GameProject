//
// Created by federico on 17/09/19.
//

#include "gtest/gtest.h"
#include "../Weapon.h"
#include "../WeaponFactory.h"

TEST(Weapon, shoot){

    WeaponFactory factory;

    Weapon* weapon = factory.createWeapon(0);

    weapon->shoot (weapon, sf::Vector2f(0,0), true);



}