//
// Created by federico on 22/09/19.
//

#include "Spike.h"
#include "Map.h"


Spike::Spike(std::string &texturePath, int id) : Item(texturePath, id, true) {

}

void Spike::interact(GameHero *player, Map &map) {

    player->setHP(player->getHp() - damage, map);

//    sf::Vector2f initialPlayerPosition(player->getSprite().getPosition());
//    player->getSprite().setPosition(map.getSpawnPoint());
//    player->getPlayerView().reset(sf::FloatRect(0.f, 100.f, map.getViewWidth(), map.getViewHeight()));


}
