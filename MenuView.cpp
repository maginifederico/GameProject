//
// Created by sode on 18/10/19.
//

#include "MenuView.h"

MenuView::MenuView(MenuController *c, MenuModel *m) : controller(c), model(m), selected(model->getCurrent()),
                                                      currentScreen(model->getScreen()) {

    model->addObserver(this);

    float windowWidth = 1920;
    float windowHeight = 1010;

    sf::Font *font = new sf::Font;
    font->loadFromFile("./Fonts/ImperfectaRegular.ttf");

    startScreenOptions.emplace_back(sf::Text("Start Game", *new sf::Font(*font)));
    startScreenOptions.emplace_back(sf::Text("Quit", *new sf::Font(*font)));

    //posizionamento startScreen
    startScreenOptions[0].setFillColor(sf::Color::Green);
    startScreenOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
    for (int i = 1; i < startScreenOptions.size(); i++) {
        startScreenOptions[i].setPosition(startScreenOptions[i - 1].getPosition().x,
                                          startScreenOptions[i - 1].getPosition().y + 70.f);

    }


    mainMenuOptions.emplace_back(sf::Text("Select level", *new sf::Font(*font)));
    mainMenuOptions.emplace_back(sf::Text("Select weapon", *new sf::Font(*font)));
    mainMenuOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));

    //posizionamento mainMenu
    mainMenuOptions[0].setPosition(50.f, 40.f);
    for (int i = 1; i < mainMenuOptions.size(); i++) {
        mainMenuOptions[i].setPosition(mainMenuOptions[i - 1].getPosition().x,
                                       mainMenuOptions[i - 1].getPosition().y + 70.f);
    }

    levelSelectOptions.emplace_back(sf::Text("1-1", *new sf::Font(*font)));
    levelSelectOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));

    //posizionamento levelSelect
    levelSelectOptions[0].setPosition((windowWidth / 2) - 80.f, (windowHeight / 2) + 40.f);
    for (int i = 1; i < levelSelectOptions.size(); i++) {
        levelSelectOptions[i].setPosition(levelSelectOptions[i - 1].getPosition().x + 300.f,
                                          levelSelectOptions[i - 1].getPosition().y);

    }

    weaponSelectOptions.emplace_back(sf::Text("French Fry Gun", *new sf::Font(*font)));
    weaponSelectOptions.emplace_back(sf::Text("French Fry Cannon", *new sf::Font(*font)));
    weaponSelectOptions.emplace_back(sf::Text("Back", *new sf::Font(*font)));

    //posizionamento weaponSelect
    weaponSelectOptions[0].setPosition(50.f, 40.f);
    for (int i = 1; i < weaponSelectOptions.size(); i++) {
        weaponSelectOptions[i].setPosition(weaponSelectOptions[i - 1].getPosition().x,
                                           weaponSelectOptions[i - 1].getPosition().y + 70.f);

    }

    delete font;

}

void MenuView::update() {

    getCurrentScreenOptions()[selected].setFillColor(sf::Color::White);
    selected = model->getCurrent();
    currentScreen = model->getScreen();
    getCurrentScreenOptions()[selected].setFillColor(sf::Color::Green);
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

std::vector<sf::Text> &MenuView::getCurrentScreenOptions() {
//    return model->getOptions();

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

