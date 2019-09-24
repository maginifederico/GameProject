//
// Created by federico on 22/09/19.
//

#ifndef GAME_CHECKPOINT_H
#define GAME_CHECKPOINT_H


#include "Item.h"
#include "Map.h"


class Checkpoint : public Item {

public:

    Checkpoint(std::string &checkpointTexturePath, int id);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override;

private:

    bool achieved;
    int animationNumber;

    sf::Clock clock;
    const float animationSpeed = 0.3f;

    std::string animationFlagPath1 = "./Textures/RedFlag1.png";
    std::string animationFlagPath2 = "./Textures/RedFlag2.png";

    sf::Texture animation1;
    sf::Texture animation2;


};


#endif //GAME_CHECKPOINT_H
