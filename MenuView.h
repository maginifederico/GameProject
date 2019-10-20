//
// Created by sode on 18/10/19.
//

#ifndef GAME_MENUVIEW_H
#define GAME_MENUVIEW_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Observer.h"
#include "MenuController.h"
#include "MenuModel.h"

class MenuView : public Observer {

public:

    MenuView(MenuController *c, MenuModel *m);

    std::vector<sf::Text> &getCurrentScreenOptions();

    void registerW();

    void registerA();

    void registerS();

    void registerD();

    bool registerSpace();

    void update() override;

private:


    MenuController *controller;

    MenuModel *model;

    std::vector<sf::Text> startScreenOptions;
    std::vector<sf::Text> mainMenuOptions;
    std::vector<sf::Text> levelSelectOptions;
    std::vector<sf::Text> weaponSelectOptions;

    int selected;
    Screen currentScreen;

//    sf::Clock clock;

};


#endif //GAME_MENUVIEW_H
