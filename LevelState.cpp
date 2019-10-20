//
// Created by sode on 18/10/19.
//

#include "LevelState.h"

State *LevelState::getNextState() {
    delete this;
    return new MenuState();
}

LevelState::LevelState() {

}
