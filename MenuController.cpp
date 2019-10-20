//
// Created by sode on 18/10/19.
//

#include "MenuController.h"

MenuController::MenuController(MenuModel *m) : model(m) {

}

bool MenuController::enter() {

    switch (model->getScreen()) {
        case start: {
            switch (model->getCurrent()) {
                case 0:
                    model->setScreen(mainMenu);
                    break;

                case 1: {
                    break;
                }

                default:
                    return false;
            }
            break;
        }
        case mainMenu: {
            switch (model->getCurrent()) {
                case 0: {
                    model->setScreen(levelSelect);
                    break;
                }

                case 1: {
                    model->setScreen(weaponSelect);
                    break;
                }

                case 2: {
                    model->setScreen(start);
                    break;
                }
                default:
                    return false;
            }
            break;
        }
        case levelSelect: {
            switch (model->getCurrent()) {
                case 0: {
                    model->setLevelNumber(1);
                    return model->enterLevel();
                }
                case 1: {
                    model->setScreen(mainMenu);
                    break;
                }
                default:
                    return false;
            }
            break;
        }
        case weaponSelect: {
            switch (model->getCurrent()) {
                case 0: {
                    model->setWeaponId(0);
                    break;
                }
                case 1: {
                    model->setWeaponId(1);
                    break;
                }
                case 2: {
                    model->setScreen(mainMenu);
                    break;
                }
                default:
                    return false;
            }
            break;
        }

        default:
            return false;
    }

    //Produci un output audio di conferma
    return false;
}

void MenuController::moveUp() {

    model->setCurrent(model->getCurrent() - 1);
}

void MenuController::moveDown() {

    model->setCurrent(model->getCurrent() + 1);
}

void MenuController::moveLeft() {

    model->setCurrent(model->getCurrent() - 1);
}

void MenuController::moveRight() {

    model->setCurrent(model->getCurrent() + 1);
}