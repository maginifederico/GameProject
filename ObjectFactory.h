//
// Created by federico on 19/09/19.
//

#ifndef GAME_OBJECTFACTORY_H
#define GAME_OBJECTFACTORY_H


#include <bits/unique_ptr.h>
#include "Item.h"
#include "Coin.h"
#include "HealthPill.h"
#include "Spike.h"
#include "Checkpoint.h"
#include "StoneGenerator.h"
#include "BlueFlag.h"
#include "Bonus.h"
#include "Door.h"

class ObjectFactory {

public:
    Item *createObject(int id, float posX, float posY);

};


#endif //GAME_OBJECTFACTORY_H
