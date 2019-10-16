#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
    //rivedere collisioni con layer ground (guardare i FIXME su GameHero)
    //aggiungere tutti gli oggetti nella ObjectsFactory (rimangono i bonus, BlueFlag, porte nere e marroni)
    //Unit Testing
    //creare nemici
    //Strategy per movimento nemici (classe base= MovementBehaviour, derivate= flying e walking behaviour)
    //Doors



    ////DA RIVEDERE

    ////DA FARE
    //TODO implementare potenziamenti armi
    //TODO smart pointer invece di raw pointer (oppure eliminare i leak con valgrind)
    //TODO Observer per Achievements
    //TODO Menù principale (con MVC, Prima creare astratte Observer e Subject. Poi Model(Subject), Controller, View(obs)
    //TODO State Pattern per stato gioco
    //TODO implementare salvataggio progressi (lettura e scrittura da file)



    ////INIT WINDOW

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    int frameRate = 160;

    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(frameRate);


    ////INIT MAP

    MapFactory mapFactory;

    Map *map;
    int id = 1;
    map = mapFactory.createMap(id);



    ////INIT PLAYER WEAPON
    WeaponFactory weaponFactory;
    const int justOne = 0;
    const int frenchFries = 1;


    ////INIT PLAYER

    Gui gui;

    GameHero player(Vector2f(map->getSpawnPoint().x, map->getSpawnPoint().y),
                    Vector2f(map->getViewWidth(), map->getViewHeight()), gui/*, weapon*/);
    player.setWeapon(weaponFactory.createWeapon(justOne));

    ////INIT GUI

    player.getGui().load(player.getPlayerView());



    ////ENEMIES
    StillBehaviour *behaviour;
    for (Enemy *enemy : map->getEnemies()) {

        behaviour = dynamic_cast<StillBehaviour *>(enemy->getMovementBehaviour());
        if (behaviour != nullptr)
            behaviour->setPlayer(&player);

    }


    const float defaultDistanceX = (player.getPlayerView().getSize().x / 2) - 125.f;
    const float defaultDistanceY = 40.f;


    ////GAME LOOP
    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (!map->isEndLevel()) {
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
            player.getSprite().move(player.getSpeed(), 0);
        }

        //update input
        player.updatePosition(*map);

        player.updateViewPosition(*map);

        player.getWeapon()->checkProjectileCollision(*map);
        player.checkCollection(*map);
        player.checkEnemyCollision(*map);

        map->updateObjects();
        player.manageBonuses();
        map->updateEnemies(player);

        ////DOOR MANAGEMENT


        for (Door *door : map->getDoors()) {
            if (player.getSprite().getGlobalBounds().intersects(door->getCollision())) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    if (!door->isDisabled()) {

                        sf::Vector2f offset = -player.getSprite().getPosition();
                        delete map;
                        map = mapFactory.createMap(door->getNextMapId());

                        for (Enemy *enemy : map->getEnemies()) {

                            behaviour = dynamic_cast<StillBehaviour *>(enemy->getMovementBehaviour());
                            if (behaviour != nullptr)
                                behaviour->setPlayer(&player);
                        }

                        player.setHP(100, *map);
                        player.getSprite().setPosition(door->getNextSpawnPoint());
                        offset += player.getSprite().getPosition();
                        player.getPlayerView().move(offset);

                        if (player.getSprite().getPosition().x !=
                            player.getPlayerView().getCenter().x - defaultDistanceX)
                            player.getPlayerView().setCenter(player.getSprite().getPosition().x + defaultDistanceX,
                                                             player.getPlayerView().getCenter().y);

                        if (player.getSprite().getPosition().y !=
                            player.getPlayerView().getCenter().y + defaultDistanceY)
                            player.getPlayerView().setCenter(player.getSprite().getPosition().x,
                                                             player.getSprite().getPosition().y + defaultDistanceY);


                        if (player.getPlayerView().getCenter().x - player.getPlayerView().getSize().x / 4 <
                            map->getViewHorizontalLimitSx())
                            player.getPlayerView().setCenter(player.getPlayerView().getSize().x / 2,
                                                             player.getPlayerView().getCenter().y);
                        if (player.getPlayerView().getCenter().x - player.getPlayerView().getSize().x / 4 >
                            map->getViewHorizontalLimitDx())
                            player.getPlayerView().setCenter(map->getWidth() - player.getPlayerView().getSize().x / 2,
                                                             player.getPlayerView().getCenter().y);
                        if (player.getPlayerView().getCenter().y + 40.f > map->getViewVerticalLimitDown())
                            player.getPlayerView().setCenter(player.getPlayerView().getCenter().x,
                                                             map->getHeight() - player.getPlayerView().getSize().y / 2);
                        if (player.getPlayerView().getCenter().y + 40.f < map->getViewVerticalLimitUp())
                            player.getPlayerView().setCenter(player.getPlayerView().getCenter().x,
                                                             player.getPlayerView().getSize().y / 2);

                        player.getGui().reset();

                        player.getGui().load(player.getPlayerView());
                        break;
                    }
                }
            }
        }

        //render
        window.clear();


        //render game elements
        window.draw(map->getLayer()[0]);
        window.draw(map->getLayer()[1]);

        for (Item *item : map->getObjectsCollector())
            window.draw(item->getSprite());

        for (Item *item :map->getAnimatedObjects()) {
            window.draw(item->getSprite());
        }

        for (Enemy *enemy: map->getEnemies()) {
            StillBehaviour *ptr;
            ptr = dynamic_cast<StillBehaviour *> (enemy->getMovementBehaviour());
            if (ptr != nullptr) {
                for (Projectile projectile : ptr->getWeapon()->getProjectiles()) {
                    window.draw(projectile.getSprite());
                }
            }
        }

        for (Door *door : map->getDoors()) {
            window.draw(door->getSprite());
        }

        for (Projectile projectile : player.getWeapon()->getProjectiles()) {
            window.draw(projectile.getSprite());
        }

        for (Enemy *enemy : map->getEnemies()) {
            window.draw(enemy->getSprite());
        }

        window.draw(player.getSprite());

        window.setView(player.getPlayerView());

        for (sf::RectangleShape current : player.getGuiShapes()) {
            window.draw(current);
        }

        for (sf::Text curren : player.getGuiText()) {
            window.draw(curren);
        }

        //render ui
        window.display();
    }

    return 0;


}