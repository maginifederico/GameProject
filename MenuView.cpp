//
// Created by sode on 18/10/19.
//

#include <iostream>
#include "MenuView.h"

MenuView::MenuView(MenuController *c, MenuModel *m) : controller(c), model(m), selected(model->getCurrent()),
                                                      currentScreen(model->getScreen()) {

    model->addObserver(this);

    float windowWidth = 1920;
    float windowHeight = 1010;

    ////INIT START SCREEN
    startScreenTextures.emplace_back(sf::Texture());
    startScreenTextures.emplace_back(sf::Texture());
    startScreenTextures.emplace_back(sf::Texture());

    startScreenOptions.emplace_back(sf::Sprite());
    startScreenOptions.emplace_back(sf::Sprite());
    startScreenOptions.emplace_back(sf::Sprite());


    if (!startScreenTextures[0].loadFromFile("./Textures/playSelected.png"))
        std::cout << "error loading texture";

    if (!startScreenTextures[1].loadFromFile("./Textures/optionSelected.png"))
        std::cout << "error loading texture";

    if (!startScreenTextures[2].loadFromFile("./Textures/quitSelected.png"))
        std::cout << "error loading texture";

    startScreenOptions[0].setTexture(startScreenTextures[0]);
    startScreenOptions[1].setTexture(startScreenTextures[1]);
    startScreenOptions[2].setTexture(startScreenTextures[2]);

    //posizionamento startScreen
    for (int i = 0; i < startScreenOptions.size(); i++) {
        startScreenOptions[i].setScale(2.f, 2.f);
        startScreenOptions[i].setPosition(windowWidth / 3, windowHeight / 7);
    }

    ////INIT MAIN MENU
    mainMenuOptionsTextures.emplace_back(sf::Texture());
    mainMenuOptionsTextures.emplace_back(sf::Texture());
    mainMenuOptionsTextures.emplace_back(sf::Texture());

    mainMenuOptions.emplace_back(sf::Sprite());
    mainMenuOptions.emplace_back(sf::Sprite());
    mainMenuOptions.emplace_back(sf::Sprite());

    if (!mainMenuOptionsTextures[0].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    if (!mainMenuOptionsTextures[1].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    if (!mainMenuOptionsTextures[2].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    mainMenuOptions[0].setTexture(mainMenuOptionsTextures[0]);
    mainMenuOptions[1].setTexture(mainMenuOptionsTextures[1]);
    mainMenuOptions[2].setTexture(mainMenuOptionsTextures[2]);


    //posizionamento mainMenu
    mainMenuOptions[0].setPosition(50.f, 40.f);
    for (int i = 1; i < mainMenuOptions.size(); i++) {
        mainMenuOptions[i].setPosition(mainMenuOptions[i - 1].getPosition().x,
                                       mainMenuOptions[i - 1].getPosition().y + 70.f);
    }


    ////INIT LEVEL SELECTION
    levelSelectOptionsTextures.emplace_back(sf::Texture());
    levelSelectOptionsTextures.emplace_back(sf::Texture());

    levelSelectOptions.emplace_back(sf::Sprite());
    levelSelectOptions.emplace_back(sf::Sprite());

    if (!levelSelectOptionsTextures[0].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    if (!levelSelectOptionsTextures[1].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";


    levelSelectOptions[0].setTexture(levelSelectOptionsTextures[0]);
    levelSelectOptions[1].setTexture(levelSelectOptionsTextures[1]);

    //posizionamento levelSelect
    levelSelectOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
    for (int i = 1; i < levelSelectOptions.size(); i++) {
        levelSelectOptions[i].setPosition(levelSelectOptions[i - 1].getPosition().x + 300.f,
                                          levelSelectOptions[i - 1].getPosition().y);

    }


    ////INIT WEAPON SELECTION
    weaponSelectOptionsTextures.emplace_back(sf::Texture());
    weaponSelectOptionsTextures.emplace_back(sf::Texture());
    weaponSelectOptionsTextures.emplace_back(sf::Texture());

    weaponSelectOptions.emplace_back(sf::Sprite());
    weaponSelectOptions.emplace_back(sf::Sprite());
    weaponSelectOptions.emplace_back(sf::Sprite());

    if (!weaponSelectOptionsTextures[0].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    if (!weaponSelectOptionsTextures[1].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    if (!weaponSelectOptionsTextures[2].loadFromFile("./Textures/Coin.png"))
        std::cout << "error loading texture";

    weaponSelectOptions[0].setTexture(weaponSelectOptionsTextures[0]);
    weaponSelectOptions[1].setTexture(weaponSelectOptionsTextures[1]);
    weaponSelectOptions[2].setTexture(weaponSelectOptionsTextures[2]);

    //posizionamento weaponSelect
    weaponSelectOptions[0].setPosition(50.f, 40.f);
    for (int i = 1; i < weaponSelectOptions.size(); i++) {
        weaponSelectOptions[i].setPosition(weaponSelectOptions[i - 1].getPosition().x,
                                           weaponSelectOptions[i - 1].getPosition().y + 70.f);

    }

////


//    sf::Font *font = new sf::Font;
//    font->loadFromFile("./Fonts/ImperfectaRegular.ttf");
//
//    startScreenOptions.emplace_back(sf::Text("Start Game", *new sf::Font(*font)));
//    startScreenOptions.emplace_back(sf::Text("Quit", *new sf::Font(*font)));
//
//    //posizionamento startScreen
//    startScreenOptions[0].setFillColor(sf::Color::Green);
//    startScreenOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
//    for (int i = 1; i < startScreenOptions.size(); i++) {
//        startScreenOptions[i].setPosition(startScreenOptions[i - 1].getPosition().x,
//                                          startScreenOptions[i - 1].getPosition().y + 70.f);
//
//    }
//
//
//    mainMenuOptions.emplace_back(sf::Text("Select level", *new sf::Font(*font)));
//    mainMenuOptions.emplace_back(sf::Text("Select weapon", *new sf::Font(*font)));
//    mainMenuOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));
//
//    //posizionamento mainMenu
//    mainMenuOptions[0].setPosition(50.f, 40.f);
//    for (int i = 1; i < mainMenuOptions.size(); i++) {
//        mainMenuOptions[i].setPosition(mainMenuOptions[i - 1].getPosition().x,
//                                       mainMenuOptions[i - 1].getPosition().y + 70.f);
//    }
//
//    levelSelectOptions.emplace_back(sf::Text("1-1", *new sf::Font(*font)));
//    levelSelectOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));
//
//    //posizionamento levelSelect
//    levelSelectOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
//    for (int i = 1; i < levelSelectOptions.size(); i++) {
//        levelSelectOptions[i].setPosition(levelSelectOptions[i - 1].getPosition().x + 300.f,
//                                          levelSelectOptions[i - 1].getPosition().y);
//
//    }
//
//    weaponSelectOptions.emplace_back(sf::Text("French Fry Gun", *new sf::Font(*font)));
//    weaponSelectOptions.emplace_back(sf::Text("French Fry Cannon", *new sf::Font(*font)));
//    weaponSelectOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));
//
//    //posizionamento weaponSelect
//    weaponSelectOptions[0].setPosition(50.f, 40.f);
//    for (int i = 1; i < weaponSelectOptions.size(); i++) {
//        weaponSelectOptions[i].setPosition(weaponSelectOptions[i - 1].getPosition().x,
//                                           weaponSelectOptions[i - 1].getPosition().y + 70.f);
//
//    }
//
//    delete font;

}

void MenuView::update() {

//    getCurrentScreenOptions()[selected].setFillColor(sf::Color::White);
    selected = model->getCurrent();
    currentScreen = model->getScreen();
//    getCurrentScreenOptions()[selected].setFillColor(sf::Color::Green);
}

bool MenuView::registerSpace() {
    return controller->enter();
}

void MenuView::registerW() {
    if (currentScreen != levelSelect && selected > 0)
        controller->moveUp();
}

void MenuView::registerA() {
    if (currentScreen == levelSelect && selected > 0)
        controller->moveLeft();
}

void MenuView::registerS() {
    if (currentScreen != levelSelect && selected < getCurrentScreenOptions().size() - 1)
        controller->moveDown();
}

void MenuView::registerD() {
    if (currentScreen == levelSelect && selected < getCurrentScreenOptions().size() - 1)
        controller->moveRight();
}


std::vector<sf::Sprite> &MenuView::getCurrentScreenOptions() {

    switch (currentScreen) {
        case start:
            return startScreenOptions;
        case mainMenu:
            return mainMenuOptions;
        case levelSelect:
            return levelSelectOptions;
        case weaponSelect:
            return weaponSelectOptions;
    }
}

