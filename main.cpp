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

    ////DA RIVEDERE
    //TODO rivedere collisioni con layer ground (guardare i FIXME su GameHero)
    //TODO aggiungere tutti gli oggetti nella ObjectsFactory (rimangono i bonus, BlueFlag, porte nere e marroni)

    ////DA FARE
    //TODO Unit Testing
    //TODO creare nemici
    //TODO Strategy per movimento nemici (classe base= MovementBehaviour, derivate= flying e wolking behaviour)
    //TODO gestione vita nemici con rettangolini rossi e verdi
    //TODO implementare i bonus
    //TODO implementare potenziamenti
    //TODO smart pointer invece di raw pointer
    //TODO Observer per Achievements
    //TODO Menù principale (con MVC, Prima creare astratte Observer e Subject. Poi Model(Subject), Controller, View(obs)
    //TODO State Pattern per stato gioco
    //TODO implementare salvataggio progressi (letturea e scrittura da file)


    //TODO ::TODAY::
    //TODO doors
    //TODO BlueFlag
    //TODO gameBonus (attack and shield)


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
    int weaponNumber = 0;

//    std::unique_ptr<Weapon> justOne = weaponFactory.createWeapon(0);

//    std::unique_ptr<Weapon> frenchFries = weaponFactory.createWeapon(1);

//    Weapon *justOne = weaponFactory.createWeapon(0);

//    Weapon *frenchFries = weaponFactory.createWeapon(1);


//    Weapon frenchFries(FRENCH_FRIES_TEXTURE, french_fries_texture_scale, french_fries_damage, french_fries_range,
//                       french_fries_cooldown);


    ////INIT PLAYER

    GameHero player(Vector2f(map->getSpawnPoint().x, map->getSpawnPoint().y),
                    Vector2f(map->getViewWidth(), map->getViewHeight())/*, weapon*/);
    player.setWeapon(weaponFactory.createWeapon(weaponNumber));

    ////INIT GUI

    player.loadGui();




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
        map->updateObjects();


        //render
        window.clear();


        //render game elements
        window.draw(map->getLayer()[0]);
        window.draw(map->getLayer()[1]);

        for (Item *item : map->getObjectsCollector())
            window.draw(item->getSprite());
//        window.draw(map.getLayer()[2]);

        for (Item *item :map->getAnimatedObjects()) {
            window.draw(item->getSprite());
        }

        for (Projectile projectile : player.getWeapon()->getProjectiles()) {
            window.draw(projectile.getSprite());
        }

        window.draw(player.getSprite());

//        window.draw(text);
        window.setView(player.getPlayerView());

//        player.updateGUIPosition(bar, health, healthIndicator, coinIndicator);
//        window.draw(bar);
//        window.draw(health);
//        window.draw(healthIndicator);

//        gui.updatePosition(player.updateViewPosition(*map));
        for (sf::RectangleShape *current : player.getGuiShapes()) {
            window.draw(*current);
//            delete current;
        }

        for (sf::Text *current : player.getGuiText()) {
            window.draw(*current);
//            delete(current);
        }
//        for (RectangleShape* shape : gui.getShapes())
//            window.draw(*shape);
//
//        for (Text* txt : gui.getText())
//            window.draw(*txt);

        //render ui
        window.display();
    }

    return 0;


}