/**
 * Project Untitled
 */


#ifndef _LEVEL_H
#define _LEVEL_H

#include "MapFactory.h"
#include "Map.h"
#include "WeaponFactory.h"

class Level {
public:

    Level();

    void loadMap(int levelNumber, GameHero &player/*, int weaponId*/);

    void manageDoors(GameHero &player);

    Map *getMap();

private:

    MapFactory mapFactory;
    Map *map;
    int mapId;

};

#endif //_LEVEL_H