/**
 * Project Untitled
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"
#include "MovementBehaviour.h"


class Enemy : public GameCharacter {

public:

    Enemy(std::string &moleTexturePath, sf::Vector2f position, float moleSpeed, float moleUnderWaterSpeed, int HP,
          int id);

    void setHP(int hp, Map &map) override {};

    void updatePosition(Map &map) override {};

private:

    MovementBehaviour *movementBehaviour;
    int id;

//    void attack();
};

#endif //_ENEMY_H