//
// Created by federico on 20/09/19.
//

#ifndef GAME_MAPFACTORY_H
#define GAME_MAPFACTORY_H

#include <bits/unique_ptr.h>
#include "Map.h"


class MapFactory {

public:

//    std::unique_ptr<Map> createMap(int id);
    Map *createMap(int id);


};

#endif //GAME_MAPFACTORY_H
