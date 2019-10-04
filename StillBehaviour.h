//
// Created by federico on 03/10/19.
//

#ifndef GAME_STILLBEHAVIOUR_H
#define GAME_STILLBEHAVIOUR_H


#include "MovementBehaviour.h"

class StillBehaviour : public MovementBehaviour {

public:
    void updatePosition(Map &map, GameCharacter &enemy) override;

    void attack() override;

private:


};


#endif //GAME_STILLBEHAVIOUR_H
