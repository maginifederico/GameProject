//
// Created by sode on 18/10/19.
//

#ifndef GAME_MENUSTATE_H
#define GAME_MENUSTATE_H


#include "State.h"
#include "MenuView.h"
#include "LevelState.h"


class MenuState : public State {

public:

    MenuState();

    State *getNextState() override;

private:

//    MenuView* view;
//    MenuController* controller;
//    MenuModel* model;

};


#endif //GAME_MENUSTATE_H
