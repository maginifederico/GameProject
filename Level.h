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

//    Gui *getGui() ;
//
//    GameHero *getPlayer() ;

private:

    MapFactory mapFactory;
    Map *map;
    int mapId;
//    WeaponFactory weaponFactory;
//    int weaponId;
//    Gui* gui;
//    GameHero* player;
//    const float defaultDistanceX = (player.getPlayerView().getSize().x / 4);
//    const float defaultDistanceY = 40.f;

};

#endif //_LEVEL_H