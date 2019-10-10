//
// Created by federico on 02/10/19.
//

#ifndef GAME_ENEMYFACTORY_H
#define GAME_ENEMYFACTORY_H


#include "WalkingBehaviour.h"
#include "FlyingBehaviour.h"
#include "StillBehaviour.h"

class EnemyFactory {

public:
    Enemy *createEnemy(int id, float posX, float posY);

};


#endif //GAME_ENEMYFACTORY_H
