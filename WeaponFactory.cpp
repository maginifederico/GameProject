//
// Created by federico on 11/10/19.
//

#include "Weapon.h"
#include "WeaponFactory.h"

std::unique_ptr<Weapon> WeaponFactory::createWeapon(int weaponNumber) {

    std::unique_ptr<Weapon> result;

    switch (weaponNumber) {

        case 0: {
            std::string JUST_ONE_TEXTURE = "./Textures/justOne.png";
            float just_one_texture_scale = 0.08f;
            int just_one_damage = 10;
            float just_one_range = 400.f;
            float just_one_cooldown = 0.2f;

            result = std::unique_ptr<Weapon>(new Weapon(JUST_ONE_TEXTURE, just_one_texture_scale, just_one_damage,
                                                        just_one_range, just_one_cooldown));

            break;
        }

        case 1: {


            std::string FRENCH_FRIES_TEXTURE = "./Textures/FrenchFriesWeapon.png";
            float french_fries_texture_scale = 0.08f;
            int french_fries_damage = 30;
            float french_fries_range = 200.f;
            float french_fries_cooldown = 0.5f;

            result = std::unique_ptr<Weapon>(new Weapon(FRENCH_FRIES_TEXTURE, french_fries_texture_scale,
                                                        french_fries_damage, french_fries_range,
                                                        french_fries_cooldown));

            break;
        }

        default:
            result = nullptr;
    }

    return result;
}