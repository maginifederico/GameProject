//
// Created by sode on 18/10/19.
//

#include "MenuState.h"

//class LevelState;

MenuState::MenuState() {

}

State *MenuState::getNextState() {
    delete this;
    return new LevelState();
}
