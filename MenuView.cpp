//
// Created by sode on 18/10/19.
//

#include <iostream>
#include "MenuView.h"

MenuView::MenuView(MenuController *c, MenuModel *m) : controller(c), model(m), selected(model->getCurrent()),
                                                      currentScreen(model->getScreen()) {

    model->addObserver(this);

//    float windowWidth = 1920;
//    float windowHeight = 1010;

    ////INIT START SCREEN
    startScreenTextures.emplace_back(sf::Texture());
    startScreenTextures.emplace_back(sf::Texture());
    startScreenTextures.emplace_back(sf::Texture());

    startScreenOptions.emplace_back(sf::Sprite());
    startScreenOptions.emplace_back(sf::Sprite());
    startScreenOptions.emplace_back(sf::Sprite());


    if (!startScreenTextures[0].loadFromFile("./Textures/selectPlay.png"))
        std::cout << "error loading texture";

    if (!startScreenTextures[1].loadFromFile("./Textures/selectOptions.png"))
        std::cout << "error loading texture";

    if (!startScreenTextures[2].loadFromFile("./Textures/selectQuit.png"))
        std::cout << "error loading texture";

    startScreenOptions[0].setTexture(startScreenTextures[0]);
    startScreenOptions[1].setTexture(startScreenTextures[1]);
    startScreenOptions[2].setTexture(startScreenTextures[2]);

    //posizionamento startScreen
    for (int i = 0; i < startScreenOptions.size(); i++) {
        startScreenOptions[i].setScale(1.f, 0.95);
        startScreenOptions[i].setPosition(0, 0);
    }

    ////INIT MAIN MENU
    mainMenuOptionsTextures.emplace_back(sf::Texture());
    mainMenuOptionsTextures.emplace_back(sf::Texture());
    mainMenuOptionsTextures.emplace_back(sf::Texture());

    mainMenuOptions.emplace_back(sf::Sprite());
    mainMenuOptions.emplace_back(sf::Sprite());
    mainMenuOptions.emplace_back(sf::Sprite());

    if (!mainMenuOptionsTextures[0].loadFromFile("./Textures/selectLevel.png"))
        std::cout << "error loading texture";

    if (!mainMenuOptionsTextures[1].loadFromFile("./Textures/selectWeapon.png"))
        std::cout << "error loading texture";

    if (!mainMenuOptionsTextures[2].loadFromFile("./Textures/backLWB.png"))
        std::cout << "error loading texture";

    mainMenuOptions[0].setTexture(mainMenuOptionsTextures[0]);
    mainMenuOptions[1].setTexture(mainMenuOptionsTextures[1]);
    mainMenuOptions[2].setTexture(mainMenuOptionsTextures[2]);


    //posizionamento mainMenu
    for (int i = 0; i < mainMenuOptions.size(); i++) {
        mainMenuOptions[i].setPosition(0.f, 0.f);
    }


    ////INIT LEVEL SELECTION
    levelSelectOptionsTextures.emplace_back(sf::Texture());
    levelSelectOptionsTextures.emplace_back(sf::Texture());

    levelSelectOptions.emplace_back(sf::Sprite());
    levelSelectOptions.emplace_back(sf::Sprite());

    if (!levelSelectOptionsTextures[0].loadFromFile("./Textures/level1Selected.png"))
        std::cout << "error loading texture";

    if (!levelSelectOptionsTextures[1].loadFromFile("./Textures/levelSelectionBack.png"))
        std::cout << "error loading texture";


    levelSelectOptions[0].setTexture(levelSelectOptionsTextures[0]);
    levelSelectOptions[1].setTexture(levelSelectOptionsTextures[1]);

    //posizionamento levelSelect
//    levelSelectOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
    for (int i = 0; i < levelSelectOptions.size(); i++) {
        levelSelectOptions[i].setPosition(0.f, 0.f);

    }


    ////INIT WEAPON SELECTION
    weaponSelectOptionsTextures.emplace_back(sf::Texture());
    weaponSelectOptionsTextures.emplace_back(sf::Texture());
    weaponSelectOptionsTextures.emplace_back(sf::Texture());

    weaponSelectOptions.emplace_back(sf::Sprite());
    weaponSelectOptions.emplace_back(sf::Sprite());
    weaponSelectOptions.emplace_back(sf::Sprite());

    if (!weaponSelectOptionsTextures[0].loadFromFile("./Textures/frenchFriesSelected.png"))
        std::cout << "error loading texture";

    if (!weaponSelectOptionsTextures[1].loadFromFile("./Textures/frenchFriesCannonSelected.png"))
        std::cout << "error loading texture";

    if (!weaponSelectOptionsTextures[2].loadFromFile("./Textures/selectBackWeapon.png"))
        std::cout << "error loading texture";

    weaponSelectOptions[0].setTexture(weaponSelectOptionsTextures[0]);
    weaponSelectOptions[1].setTexture(weaponSelectOptionsTextures[1]);
    weaponSelectOptions[2].setTexture(weaponSelectOptionsTextures[2]);

    //posizionamento weaponSelect
    for (int i = 0; i < weaponSelectOptions.size(); i++) {
        weaponSelectOptions[i].setPosition(0.f, 0.f);

    }

    ////INIT SETTINGS
    settingsTextures.emplace_back(sf::Texture());
    settingsTextures.emplace_back(sf::Texture());
    settingsTextures.emplace_back(sf::Texture());

    settingsOptions.emplace_back(sf::Sprite());
    settingsOptions.emplace_back(sf::Sprite());
    settingsOptions.emplace_back(sf::Sprite());

    if (!settingsTextures[0].loadFromFile("./Textures/soundOptionON.png"))
        std::cout << "error loading texture";

    if (!settingsTextures[1].loadFromFile("./Textures/soundOptionOFF.png"))
        std::cout << "error loading texture";

    if (!settingsTextures[2].loadFromFile("./Textures/soundOptionBack.png"))
        std::cout << "error loading texture";

    settingsOptions[0].setTexture(settingsTextures[0]);
    settingsOptions[1].setTexture(settingsTextures[1]);
    settingsOptions[2].setTexture(settingsTextures[2]);

    for (int i = 0; i < settingsOptions.size(); i++) {
        settingsOptions[i].setPosition(0.f, 0.f);
    }
}

void MenuView::update() {

    selected = model->getCurrent();
    currentScreen = model->getScreen();
}

void MenuView::registerSpace() {
    controller->enter();
}

void MenuView::registerW() {
    if (selected > 0)
        controller->moveUp();
}

void MenuView::registerA() {
    if (selected > 0)
        controller->moveLeft();
}

void MenuView::registerS() {
    if (selected < getCurrentScreenOptions().size() - 1)
        controller->moveDown();
}

void MenuView::registerD() {
    if (selected < getCurrentScreenOptions().size() - 1)
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
        case options:
            return settingsOptions;
    }
}

