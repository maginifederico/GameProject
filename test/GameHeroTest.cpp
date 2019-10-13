//
// Created by federico on 10/09/19.
//

#include "gtest/gtest.h"
#include "../GameHero.h"

TEST(GameHero, Constructor) {

    GameHero hero(sf::Vector2f(100.f, 0.f), sf::Vector2f(800.f, 525.f), nullptr, 0, 0, 0, std::__cxx11::string(),
                  <#initializer#>);

    ASSERT_EQ(100.f, hero.getSprite().getPosition().x);
    ASSERT_EQ(0.f, hero.getSprite().getPosition().y);
    ASSERT_TRUE(hero.getMovementDirection());

}

TEST(GameHero, Collision) {

    Map map(6300.f, 525.f, sf::Vector2f(0, 0), "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt", "objectsLevel1",
            1);
    map.load();
    map.setViewLimits();
    Gui gui;
    GameHero hero(map.getSpawnPoint(), sf::Vector2f(800.f, 525.f), nullptr, 0, 0, 0, std::__cxx11::string(),
                  <#initializer#>);
    hero.setGui(gui);
    hero.getGui().load(hero.getPlayerView());

    int c = (int) hero.getSprite().getPosition().x / 21;
    int r = (int) hero.getSprite().getPosition().y / 21;

    int left = map.getLayer()[1].getTile()[c + r * 300].getId();
    int right = map.getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int down_left = map.getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int down_right = map.getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();

    //si posiziona il giocatore in terra in uno spigolo e si invoca il metodo move
    hero.getSprite().setPosition(336.f, 336.6f);
    hero.updatePosition(map);

    //velocity.y dev'essere zero, cioè il giocatore non deve essersi mosso verticalmente
    ASSERT_FLOAT_EQ(0, hero.getVelocity().y);

    //essendoci un ostacolo a destra, il movimento a destra dev'essere impedito, quindi il giocatore non deve cambiare posizione
    hero.setVelocity(sf::Vector2f(1.f, 0.f));
    hero.updatePosition(map);
    ASSERT_FLOAT_EQ(336.f, hero.getSprite().getPosition().x);

    hero.getSprite().setPosition(3.f, 0.f);
    do {
        hero.updatePosition(map);
    } while (hero.getVelocity().y != 0.f);

    c = (int) hero.getSprite().getPosition().x / 21;
    r = (int) hero.getSprite().getPosition().y / 21;

    down_left = map.getLayer()[1].getTile()[c + r * 300 + 300].getId();
    down_right = map.getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();

    ASSERT_EQ(34, down_left);
    ASSERT_EQ(34, down_right);

}
