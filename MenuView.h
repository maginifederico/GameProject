//
// Created by sode on 18/10/19.
//

#ifndef GAME_MENUVIEW_H
#define GAME_MENUVIEW_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Observer.h"
#include "MenuController.h"
#include "MenuModel.h"

class MenuView : public Observer {

public:

    MenuView(MenuController *c, MenuModel *m);

    std::vector<sf::Sprite> &getCurrentScreenOptions();

    void registerW();

    void registerA();

    void registerS();

    void registerD();

    bool registerSpace();

    void update() override;

private:


    MenuController *controller;

    MenuModel *model;

    std::vector<sf::Texture> startScreenTextures;
    std::vector<sf::Texture> mainMenuOptionsTextures;
    std::vector<sf::Texture> levelSelectOptionsTextures;
    std::vector<sf::Texture> weaponSelectOptionsTextures;

    std::vector<sf::Sprite> startScreenOptions;
    std::vector<sf::Sprite> mainMenuOptions;
    std::vector<sf::Sprite> levelSelectOptions;
    std::vector<sf::Sprite> weaponSelectOptions;

    int selected;
    Screen currentScreen;

//    sf::Clock clock;

};


#endif //GAME_MENUVIEW_H
