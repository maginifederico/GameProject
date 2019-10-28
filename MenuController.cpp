//
// Created by sode on 18/10/19.
//

#include "MenuController.h"

MenuController::MenuController(MenuModel *m) : model(m) {

}

void MenuController::enter() {

    switch (model->getScreen()) {
        case start: {
            switch (model->getCurrent()) {
                case 0:
                    model->setScreen(mainMenu);
                    break;

                case 1: {
                    model->setScreen(options);
                    break;
                }

                case 2: {
                    break;
                }

                default:
                    return;
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
                    return;
            }
            break;
        }
        case levelSelect: {
            switch (model->getCurrent()) {
                case 0: {
                    model->setLevelNumber(1);
                    break;
                }
                case 1: {
                    model->setScreen(mainMenu);
                    break;
                }
                default:
                    return;
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
                    return;
            }
            break;
        }

        case options: {
            switch (model->getCurrent()) {
                case 0: {
                    //enable music
                    model->setMusicEnabled(true);
                    break;
                }

                case 1: {
                    //disable music
                    model->setMusicEnabled(false);
                    break;
                }

                case 2: {
                    model->setScreen(start);
                    break;
                }

                default:
                    return;
            }
            break;
        }

        default:
            return;
    }

    //Produci un output audio di conferma
    return;
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