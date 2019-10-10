//
// Created by federico on 03/10/19.
//

#ifndef GAME_STILLBEHAVIOUR_H
#define GAME_STILLBEHAVIOUR_H


#include "MovementBehaviour.h"
#include "Projectile.h"
#include "GameHero.h"

class StillBehaviour : public MovementBehaviour {

public:
    StillBehaviour(Direction dir);

    void updatePosition(Map &map, Enemy &enemy) override;

    void attack() override;

    void setPlayer(GameHero *player);

    Weapon *getWeapon() const;

    ~StillBehaviour();

private:

    Weapon *weapon;
    
    GameHero *player;
};


#endif //GAME_STILLBEHAVIOUR_H
