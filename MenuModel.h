//
// Created by sode on 18/10/19.
//

#ifndef GAME_MENUMODEL_H
#define GAME_MENUMODEL_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Subject.h"
#include "State.h"

enum Screen {
    start,
    mainMenu,
    levelSelect,
    weaponSelect
};

class MenuModel : public Subject {

public:

    MenuModel(State *s);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

    bool enterLevel();

    Screen getScreen() const;

    void setScreen(Screen screen);

    int getCurrent() const;

    void setCurrent(int current);

    void setLevelNumber(int levelNumber);

    void setWeaponId(int weaponId);

    int getLevelNumber() const;

    int getWeaponId() const;

private:

    Screen screen;

    int current;

    int levelNumber;
    int weaponId;

    std::vector<Observer *> observers;

    State *state;

};


#endif //GAME_MENUMODEL_H
