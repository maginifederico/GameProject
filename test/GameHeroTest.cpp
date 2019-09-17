//
// Created by federico on 10/09/19.
//

#include "gtest/gtest.h"
#include "../GameHero.h"

TEST(GameHero, Constructor) {

    GameHero hero("./Textures/PotatoDX.png", sf::Vector2f(100.f, 0.f), sf::Vector2f(800.f, 525.f));

    ASSERT_EQ(100.f, hero.getSprite().getPosition().x);
    ASSERT_EQ(0.f, hero.getSprite().getPosition().y);
    ASSERT_TRUE(hero.getMovementDirection());

}

TEST(GameHero, Collision) {

    Map map(300, 25, sf::Vector2f(0, 0), "./Map/backgroundLevel1.txt", "./Map/groundLevel1.txt", "objectsLevel1");
    map.load();
    GameHero hero("./Textures/PotatoDX.png", map.getSpawnPoint(), sf::Vector2f(800.f, 525.f));
    hero.map = &map;

    int c = (int) hero.getSprite().getPosition().x / 21;
    int r = (int) hero.getSprite().getPosition().y / 21;

    int left = map.getLayer()[1].getTile()[c + r * 300].getId();
    int right = map.getLayer()[1].getTile()[c + r * 300 + 1].getId();
    int down_left = map.getLayer()[1].getTile()[c + r * 300 + 300].getId();
    int down_right = map.getLayer()[1].getTile()[c + r * 300 + 300 + 1].getId();

    //si posiziona il giocatore in terra in uno spigolo e si invoca il metodo move
    hero.getSprite().setPosition(336.f, 336.72f);
    hero.updatePosition();

    //velocity.y dev'essere zero, cioè il giocatore non deve essersi mosso verticalmente
    ASSERT_EQ(0, hero.getVelocity().y);

    //essendoci un ostacolo a destra, il movimento a destra dev'essere impedito, quindi il giocatore non deve cambiare posizione
    hero.setVelocity(sf::Vector2f(1.f, 0.f));
    hero.updatePosition();
    ASSERT_EQ(336.f, hero.getSprite().getPosition().x);

}
