//
// Created by federico on 28/09/19.
//

#ifndef GAME_DOORFACTORY_H
#define GAME_DOORFACTORY_H


#include "Door.h"

class DoorFactory {

public:
    Door *createDoor(int id, int mapID, int column, float posX, float posY);

};


#endif //GAME_DOORFACTORY_H
