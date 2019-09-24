//
// Created by federico on 23/09/19.
//

#ifndef GAME_STONE_H
#define GAME_STONE_H


#include "Item.h"

class Stone : public Item {

public:

    Stone(sf::FloatRect collision, std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override;


private:

    void autoDestroy(std::vector<Item *> &animatedObjects, std::vector<Item *> &objects);

    const float stoneSpeed = 2.f;
    const int damage = 20;

};


#endif //GAME_STONE_H
