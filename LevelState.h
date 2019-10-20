//
// Created by sode on 18/10/19.
//

#ifndef GAME_LEVELSTATE_H
#define GAME_LEVELSTATE_H


#include "State.h"
#include "MenuState.h"
#include "Level.h"

class MenuState;

class LevelState : public State {

public:

    LevelState();

//    Level& generateLevel(int levelNumber, int weaponId);

    State *getNextState() override;

private:

};


#endif //GAME_LEVELSTATE_H
