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

    ////DA RIVEDERE
    //TODO rivedere collisioni con layer ground (guardare i FIXME su GameHero)

    ////DA FARE
    //TODO collisioni con layer oggetti
    //TODO Unit Testing
    //TODO Factory per Map
    //TODO Caverna e Stanza Speciale in Liv.1
    //TODO smart pointer invece di raw pointer
    //TODO gestione vita player e nemici con rettangolini rossi e verdi
    //TODO Observer per Achievements
    //TODO Menù principale
    //TODO State Pattern per stato gioco
    //TODO creare nemici
    //TODO Strategy per movimento nemici
    //TODO implementare i bonus e monetine
    //TODO implementare potenziamenti
    //TODO implementare salvataggio progressi

    //today: health bar
    //TODO today: coin counter
    //TODO today: die() method
    //TODO today: more unit testing


    //init game

    const unsigned int WINDOW_WIDTH = 1920;
    const unsigned int WINDOW_HEIGHT = 1010;
    const float VIEW_HEIGHT = 300.f;
    const float VIEW_WIDTH = 500.f;
    const std::string GAME_HERO_TEXTURE = "./Textures/PotatoDX.png";


//    ////LEVEL 1 SETTINGS
//    float mapWidth = 6300.f;
//    float mapHeight = 525.f;
//    Vector2f spawnPoint(100.f, 300.f);


    //init window
    RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PATAMAN ADVENTURES");
    window.setFramerateLimit(160);


    ////INIT MAP


    //LOAD LEVEL 1
//    Map map(mapWidth, mapHeight, spawnPoint, "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt",
//            "./Map/objectsLevel1");
//    map.load();

    //SETTA I LIMITI DELLA VIEW
//    map.setViewLimits(VIEW_WIDTH, VIEW_HEIGHT);

    MapFactory mapFactory;

    Map *map;
    int id = 1;
    map = mapFactory.createMap(id);
    map->setViewLimits(VIEW_WIDTH, VIEW_HEIGHT);




    ////INIT PLAYER WEAPONS

    WeaponFactory weaponFactory;
    int weaponNumber = 0;

//    std::unique_ptr<Weapon> justOne = weaponFactory.createWeapon(0);

//    std::unique_ptr<Weapon> frenchFries = weaponFactory.createWeapon(1);

//    Weapon *justOne = weaponFactory.createWeapon(0);

//    Weapon *frenchFries = weaponFactory.createWeapon(1);


//    Weapon frenchFries(FRENCH_FRIES_TEXTURE, french_fries_texture_scale, french_fries_damage, french_fries_range,
//                       french_fries_cooldown);


    //init game elements

    ////INIT Player
    GameHero player(GAME_HERO_TEXTURE, Vector2f(map->getSpawnPoint().x, map->getSpawnPoint().y),
                    Vector2f(VIEW_WIDTH, VIEW_HEIGHT)/*, weapon*/);
    player.setWeapon(weaponFactory.createWeapon(weaponNumber));





    ////INIT GUI

    Gui gui(player.playerView);



    ////GAME LOOP
    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

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

        //update input
        player.updatePosition(*map);

        gui.updatePosition(player.updateViewPosition(*map));

        player.getWeapon()->checkProjectileCollision(*map);

        player.checkCollection(*map);

        //render
        window.clear();


        //render game elements
        window.draw(map->getLayer()[0]);
        window.draw(map->getLayer()[1]);

//        for(Item * item : map.getObjectsCollector()){
//
//            window.draw(item->getSprite());
//
//        }
        for (Item *item : map->getObjectsCollector())
            window.draw(item->getSprite());
//        window.draw(map.getLayer()[2]);

        for (Projectile projectile : player.getWeapon()->getProjectiles()) {
            window.draw(projectile.getSprite());
        }

        window.draw(player.getSprite());

//        window.draw(text);
        window.setView(player.playerView);

//        player.updateGUIPosition(bar, health, healthIndicator, coinIndicator);
//        window.draw(bar);
//        window.draw(health);
//        window.draw(healthIndicator);

//        gui.updatePosition(player.updateViewPosition(*map));
        gui.draw(window);
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