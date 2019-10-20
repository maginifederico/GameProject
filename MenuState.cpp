//
// Created by sode on 18/10/19.
//

#include "MenuState.h"

//class LevelState;

MenuState::MenuState() {

//    model = new MenuModel();
//    controller = new MenuController(model);
//    view = new MenuView(controller, model);

}

State *MenuState::getNextState() {
    delete this;
    return new LevelState();
}
