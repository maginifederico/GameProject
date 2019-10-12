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



    ////DA RIVEDERE
    //TODO rivedere collisioni con layer ground (guardare i FIXME su GameHero)
    //TODO aggiungere tutti gli oggetti nella ObjectsFactory (rimangono i bonus, BlueFlag, porte nere e marroni)

    ////DA FARE
    //TODO Unit Testing
    //TODO creare nemici
    //TODO Strategy per movimento nemici (classe base= MovementBehaviour, derivate= flying e walking behaviour)
    //TODO implementare potenziamenti armi
    //TODO smart pointer invece di raw pointer (oppure eliminare i leak con valgrind)
    //TODO Observer per Achievements
    //TODO Menù principale (con MVC, Prima creare astratte Observer e Subject. Poi Model(Subject), Controller, View(obs)
    //TODO State Pattern per stato gioco
    //TODO implementare salvataggio progressi (lettura e scrittura da file)


    //TODO ::TODAY::
    //TODO doors



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
    int id = 3;
    map = mapFactory.createMap(id);



    ////INIT PLAYER WEAPON
    WeaponFactory weaponFactory;
    const int justOne = 0;
    const int frenchFries = 1;


    ////INIT PLAYER
    GameHero player(Vector2f(map->getSpawnPoint().x, map->getSpawnPoint().y),
                    Vector2f(map->getViewWidth(), map->getViewHeight())/*, weapon*/);
    player.setWeapon(weaponFactory.createWeapon(frenchFries));

    ////INIT GUI
    player.loadGui();



    ////ENEMIES
    StillBehaviour *behaviour;
    for (Enemy *enemy : map->getEnemies()) {

        behaviour = dynamic_cast<StillBehaviour *>(enemy->getMovementBehaviour());
        if (behaviour != nullptr)
            behaviour->setPlayer(&player);

    }



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
                        sf::Vector2f offset = player.getSprite().getPosition();
                        map = mapFactory.createMap(door->getNextMapId());
                        player.getSprite().setPosition(door->getNextSpawnPoint());
                        offset = player.getSprite().getPosition() - offset;
                        player.getPlayerView().move(offset);
                        //SISTEMARE RESPAWN
//                        player.getPlayerView().reset(
//                                sf::FloatRect(map->getSpawnPoint().x, map->getSpawnPoint().y, map->getViewWidth(),
//                                              map->getViewHeight()));

//                      player.updateViewPosition(*map);

                        player.loadGui();
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

        for (sf::RectangleShape *current : player.getGuiShapes()) {
            window.draw(*current);
        }

        for (sf::Text *current : player.getGuiText()) {
            window.draw(*current);
        }

        //render ui
        window.display();
    }

    return 0;


}