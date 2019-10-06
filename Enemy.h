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
          int id, MovementBehaviour *behaviour, int melee);

    void setHP(int hp, Map &map) override;

    void updatePosition(Map &map) override {
        movementBehaviour->updatePosition(map, *this);
    };

    int getMeleeDamage() const;

    MovementBehaviour *getMovementBehaviour() const;

    int getId() const;

private:

    MovementBehaviour *movementBehaviour;
    int id;
    int meleeDamage;

//    void attack();
};

#endif //_ENEMY_H