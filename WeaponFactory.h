//
// Created by federico on 17/09/19.
//

#ifndef GAME_WEAPONFACTORY_H
#define GAME_WEAPONFACTORY_H

#include <bits/unique_ptr.h>
#include "Weapon.h"

class WeaponFactory {

public:
//    virtual ~WeaponFactory();

    virtual std::unique_ptr<Weapon> createWeapon(int weaponNumber);


};

#endif //GAME_WEAPONFACTORY_H
