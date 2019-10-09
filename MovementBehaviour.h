/**
 * Project Untitled
 */


#ifndef _MOVEMENTBEHAVIOUR_H
#define _MOVEMENTBEHAVIOUR_H

#include "Map.h"

class MovementBehaviour {
public:

    virtual void updatePosition(Map &map, Enemy &enemy) = 0;

    virtual void attack() = 0;


protected:
    bool rightDirection;

};

#endif //_MOVEMENTBEHAVIOUR_H