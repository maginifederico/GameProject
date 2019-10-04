/**
 * Project Untitled
 */


#ifndef _WALKINGBEHAVIOUR_H
#define _WALKINGBEHAVIOUR_H

#include "MovementBehaviour.h"


class WalkingBehaviour : public MovementBehaviour {

public:
    explicit WalkingBehaviour(bool dir = false);

    void updatePosition(Map &map, GameCharacter &enemy) override;

    void attack() override;

private:

    std::string leftTexturePath = "./Textures/MoleGroundEnemySX.png";
    std::string rightTexturePath = "./Textures/MoleGroundEnemyDX.png";

    sf::Texture leftTextureDirection;
    sf::Texture rightTextureDirection;


};

#endif //_WALKINGBEHAVIOUR_H