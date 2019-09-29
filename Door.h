//
// Created by federico on 27/09/19.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H


#include "Item.h"

class Door : public Item {

public:

    Door(int levelNumber, int doorNumber, std::string texturePath, int id);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override;


private:

    bool disabled;

    std::string mapPathToLoad;

    sf::Vector2f nextSpawnPoint;

};


#endif //GAME_DOOR_H
