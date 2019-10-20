//
// Created by sode on 18/10/19.
//

#include "MenuModel.h"

MenuModel::MenuModel(State *s) : screen(start), current(0), levelNumber(-1), weaponId(0), state(s) {

}

//void MenuModel::loadStart() {
//
//    screen = start;
//    current = 0;
//    notify();
//}
//
//void MenuModel::loadMain() {
//
//    screen = mainMenu;
//    current = 0;
//    notify();
//}
//
//void MenuModel::loadLevels() {
//
//    screen = levelSelect;
//    current = 0;
//    notify();
//}
//
//void MenuModel::loadWeapons() {
//
//    screen = weaponSelect;
//    current = 0;
//    notify();
//}

void MenuModel::addObserver(Observer *o) {
    observers.emplace_back(o);
}

void MenuModel::removeObserver(Observer *o) {

    for (int i = 0; i < observers.size(); i++) {
        if (observers[i] == o) {
            observers.erase(observers.begin() + i);
            return;
        }

    }
}

void MenuModel::notify() {

    for (Observer *o : observers)
        o->update();

}

Screen MenuModel::getScreen() const {
    return screen;
}

void MenuModel::setScreen(Screen s) {

    current = 0;
    screen = s;
    notify();

}

int MenuModel::getCurrent() const {
    return current;
}

void MenuModel::setCurrent(int c) {

    current = c;
    notify();
}

void MenuModel::setLevelNumber(int lN) {
    levelNumber = lN;
}

void MenuModel::setWeaponId(int wI) {
    weaponId = wI;
}

bool MenuModel::enterLevel() {
    return true;
}

int MenuModel::getLevelNumber() const {
    return levelNumber;
}

int MenuModel::getWeaponId() const {
    return weaponId;
}

//void MenuModel::quitGame() {
//
//}
