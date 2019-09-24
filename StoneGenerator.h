//
// Created by federico on 23/09/19.
//

#ifndef GAME_STONEGENERATOR_H
#define GAME_STONEGENERATOR_H


#include "Item.h"

class StoneGenerator : public Item {

public:
    StoneGenerator(float posX, float posY, std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override {};

    void update(Map *map) override;

private:

    sf::Clock clock;
    const float spawnTime = 0.8f;
    std::string stoneTexturePath;

    sf::Vector2f spawnPoint;

};


#endif //GAME_STONEGENERATOR_H
