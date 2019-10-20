//
// Created by sode on 18/10/19.
//

#include "LevelState.h"

State *LevelState::getNextState() {
    delete this;
    return new MenuState();
}

//Level &LevelState::generateLevel(int levelNumber, int weaponId) {
//
//    Level* level = new Level(levelNumber, weaponId);
//    return *level;
//
//}

LevelState::LevelState() {

}
