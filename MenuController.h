//
// Created by sode on 18/10/19.
//

#ifndef GAME_MENUCONTROLLER_H
#define GAME_MENUCONTROLLER_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "MenuModel.h"

class MenuController {

public:

    MenuController(MenuModel *m);

//        void doAction(sf::Keyboard::Key key);
    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    bool enter();

private:

    MenuModel *model;

//    sf::Clock clock;

};


#endif //GAME_MENUCONTROLLER_H
