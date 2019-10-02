//
// Created by federico on 27/09/19.
//

#ifndef GAME_BLUEFLAG_H
#define GAME_BLUEFLAG_H


#include "Item.h"
#include "Map.h"


class BlueFlag : public Item {

public:
    BlueFlag(std::string &texturePath, int id);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override;

private:
    int animationNumber;

    sf::Clock clock;
    const float animationSpeed = 0.3f;

    std::string animationFlagPath1 = "./Textures/BlueFlag1.png";
    std::string animationFlagPath2 = "./Textures/BlueFlag2.png";

    sf::Texture animation1;
    sf::Texture animation2;


};


#endif //GAME_BLUEFLAG_H
