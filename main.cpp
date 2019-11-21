#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/Music.hpp>
#include <fstream>
#include "Layer.h"
#include "GameHero.h"
#include "GameCharacter.h"
#include "Map.h"
#include "WeaponFactory.h"
#include "MapFactory.h"
#include "Gui.h"
#include "Enemy.h"
#include "StillBehaviour.h"
#include "MenuState.h"
#include "LevelState.h"
//#include <SFML/Audio/SoundSource.hpp>

using namespace sf;


int main() {

    ////FATTO
    //collisioni con layer ground
    //movimento nell'acqua
    //far sparare il giocatore
    //fps ridotto da 1500 a 160
    //collisione dei proiettili con layer ground
    //movimento view verticale
    //Factory per armi

    //Gestione input nel main
    //Metodo shoot del player
    //Tolta mappa in player, passata map ad updatePosition
    //Proiettili con intersect
    //Factory per Map
    //Factory per oggetti
    //Caverna e Stanza Speciale in Liv.1
    //Collisioni con layer oggetti
    //monetine
    //gestione vita player
    //coin counter
    //die() & setHp() method
    //checkpoint
    //fallingStones
    //spawnPoint
    //reset GUI
    //Gestione vita player

    //BlueFlag
    //gameBonus (attack and shield)
    //conto vite
    //rivedere collisioni con layer ground
    //creare nemici
    //Strategy per movimento nemici (classe base= MovementBehaviour, derivate= flying e walking behaviour)

    //Doors
    //Menù principale (con MVC, Prima creare astratte Observer e Subject. Poi Model(Subject), Controller, View(obs)
    //State Pattern per stato gioco
    //gui nel main
    //metodo checkProjectileCollision aggiornato
    //tolto checkProjectile collision da StillBehaviour
    //Unit Testing
    //aggiungere tutti gli oggetti nella ObjectsFactory



    ////INIT WINDOW
    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    int frameRate = 160;

    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(frameRate);

    ////INIT GAME CLOCK
    Clock clock;

    ////INIT MUSIC
    sf::Music levelMusic;
    if (!levelMusic.openFromFile("./Music/Level1Theme.ogg"))
        return -1; // error

    sf::Music menuMusic;
    if (!menuMusic.openFromFile("./Music/MenuTheme.ogg"))
        return -1;

    levelMusic.setLoop(true);
    menuMusic.setLoop(true);

    menuMusic.play();

    ////INIT GAME STATE
    State *gameState = new MenuState();
    gameState->setStateChanged(false);

    LevelState *copyState;


    ////INIT PLAYER WEAPON;
    WeaponFactory weaponFactory;
    const int justOne = 0;
    const int frenchFries = 1;


    ////INIT PLAYER
    Gui gui;

    GameHero player(Vector2f(), Vector2f(), gui);

    gui.setSubject(&player);
    player.addObserver(&gui);

    player.setWeapon(weaponFactory.createWeapon(justOne));

    ////INIT GUI
    player.getGui().load(player.getPlayerView());


    ////INIT MENU
    MenuModel modelMVC;
    MenuController controllerMVC(&modelMVC);
    MenuView viewMVC(&controllerMVC, &modelMVC);

    ////INIT LEVEL
    Level level;

    ////GAME LOOP
    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        copyState = dynamic_cast<LevelState *>(gameState);

        if (copyState != nullptr) {

            if (gameState->isStateChanged()) {

                if (menuMusic.getStatus() != sf::Music::Stopped)
                    menuMusic.stop();
                if (modelMVC.isMusicEnabled())
                    levelMusic.play();

                window.clear();

                level.loadMap(modelMVC.getLevelNumber(), player);
                player.getSprite().setPosition(level.getMap()->getSpawnPoint().x, level.getMap()->getSpawnPoint().y);
                player.getPlayerView().reset(
                        sf::FloatRect(0.f, 100.f, level.getMap()->getViewWidth(), level.getMap()->getViewHeight()));

                player.setHP(100, *level.getMap());
                player.setLives(3);

                gui.reset();
                gui.updateCoinCount();
                gui.load(player.getPlayerView());
                gui.updateLivesCount(3);
                player.setWeapon(weaponFactory.createWeapon(modelMVC.getWeaponId()));

                gameState->setStateChanged(false);

            }

            if (!level.getMap()->isEndLevel()) {
                //user input
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    player.setWPressed(true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    player.setAPressed(true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    player.setSPressed(true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    player.setDPressed(true);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    player.shoot();
                }

            } else {

                if (player.getSprite().getPosition().x <
                    level.getMap()->getWidth() - 2 * player.getSprite().getGlobalBounds().width)
                    player.getSprite().move(player.getSpeed(), 0);
                else {
                    gameState = gameState->getNextState();
                }
            }

            //update input
            player.updatePosition(*level.getMap());

            player.updateViewPosition(*level.getMap());

            player.getWeapon()->checkProjectileCollision(*level.getMap());
            player.checkCollection(*level.getMap());
            player.checkEnemyCollision(*level.getMap());

            level.getMap()->updateObjects();
            player.manageBonuses();
            level.getMap()->updateEnemies(player);

            if (player.isDead()) {
                gameState = gameState->getNextState();
                player.setDead(false);
            }
            ////DOOR MANAGEMENT

            level.manageDoors(player);

            //render
            window.clear();


            //render game elements
            window.draw(level.getMap()->getLayer()[0]);
            window.draw(level.getMap()->getLayer()[1]);

            for (Item *item : level.getMap()->getObjectsCollector())
                window.draw(item->getSprite());

            for (Item *item :level.getMap()->getAnimatedObjects()) {
                window.draw(item->getSprite());
            }

            for (Enemy *enemy: level.getMap()->getEnemies()) {
                StillBehaviour *behaviour;
                behaviour = dynamic_cast<StillBehaviour *> (enemy->getMovementBehaviour());
                if (behaviour != nullptr) {
                    for (Projectile projectile : behaviour->getWeapon()->getProjectiles()) {
                        window.draw(projectile.getSprite());
                    }
                }
            }

            for (Door *door : level.getMap()->getDoors()) {
                window.draw(door->getSprite());
            }

            for (Projectile projectile : player.getWeapon()->getProjectiles()) {
                window.draw(projectile.getSprite());
            }

            for (Enemy *enemy : level.getMap()->getEnemies()) {
                window.draw(enemy->getSprite());
            }

            window.draw(player.getSprite());

            window.setView(player.getPlayerView());

            for (sf::RectangleShape current : player.getGuiShapes()) {
                window.draw(current);
            }

            for (sf::Text current : player.getGuiText()) {
                window.draw(current);
            }

            //render ui
            window.display();


        } else {

            if (gameState->isStateChanged()) {

                if (levelMusic.getStatus() != sf::Music::Stopped)
                    levelMusic.stop();
                if (modelMVC.isMusicEnabled())
                    menuMusic.play();

                window.clear();
                window.setView(window.getDefaultView());

                modelMVC.setScreen(mainMenu);
                modelMVC.setCurrent(0);
                modelMVC.setLevelNumber(-1);

                gameState->setStateChanged(false);
            }

            if (clock.getElapsedTime().asSeconds() > 0.2f) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    viewMVC.registerW();
                    clock.restart();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    viewMVC.registerA();
                    clock.restart();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    viewMVC.registerS();
                    clock.restart();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    viewMVC.registerD();
                    clock.restart();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    if (modelMVC.getScreen() == start && modelMVC.getCurrent() == 2) {
                        window.close();
                        return 0;
                    }

                    viewMVC.registerSpace();

                    if (!modelMVC.isMusicEnabled() && menuMusic.getStatus() == sf::Music::Playing)
                        menuMusic.stop();

                    if (modelMVC.isMusicEnabled() && menuMusic.getStatus() == sf::Music::Stopped)
                        menuMusic.play();


                    if (modelMVC.getLevelNumber() != -1) {
                        gameState = gameState->getNextState();
                    }
                    clock.restart();
                }
            }

            window.clear();

            window.draw(viewMVC.getCurrentScreenOptions()[modelMVC.getCurrent()]);

            //render ui
            window.display();
        }
    }

    return 0;


}