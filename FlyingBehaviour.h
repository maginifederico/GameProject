/**
 * Project Untitled
 */


#ifndef _FLYINGBEHAVIOUR_H
#define _FLYINGBEHAVIOUR_H

#include "MovementBehaviour.h"
#include "Map.h"


class FlyingBehaviour : public MovementBehaviour {

public:
    void updatePosition(Map &map, GameCharacter &enemy) override;

    void attack() override;

};

#endif //_FLYINGBEHAVIOUR_H