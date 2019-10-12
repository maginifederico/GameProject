//
// Created by federico on 27/09/19.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H


#include "Item.h"

class Door : public Item {

public:

    explicit Door(sf::Vector2f nextMapPosition, int nextMapID, std::string doorTexturePath, int id,
                  bool disabled = false);

    void interact(GameHero *player, Map &map) override;

    void update(Map *map) override;

    int getNextMapId() const;

    const sf::Vector2f &getNextSpawnPoint() const;

    bool isDisabled() const;

private:

    bool disabled;

    int nextMapID;

    sf::Vector2f nextSpawnPoint;

};


#endif //GAME_DOOR_H
