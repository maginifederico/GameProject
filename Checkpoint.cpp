//
// Created by federico on 22/09/19.
//

#include "Checkpoint.h"

Checkpoint::Checkpoint(std::string &checkpointTexturePath, int id) : Item(checkpointTexturePath, id), achieved(false),
                                                                     animationNumber(0) {

    if (!animation1.loadFromFile(animationFlagPath1))
        std::cout << "Unable to load the sprite";

    if (!animation2.loadFromFile(animationFlagPath2))
        std::cout << "Unable to load the sprite";

}

void Checkpoint::interact(GameHero *player, Map &map) {


    //SCRITTA CHECKPOINT SULLO SCHERMO
    //SETTARE IL RESPAWN QUI

    map.setSpawnPoint(getSprite().getPosition());



    getSprite().setTexture(animation1);
    animationNumber = 1;

    for (int y = 0; y < map.getObjectsCollector().size(); y++)
        if (map.getObjectsCollector()[y] == this) {
            map.getObjectsCollector().erase(map.getObjectsCollector().begin() + y);
            break;
        }

    //Aggiungi la bandierina agli oggetti animati
    map.getAnimatedObjects().push_back(this);


}

void Checkpoint::update(Map *map) {


    if (clock.getElapsedTime().asSeconds() > animationSpeed) {
        if (animationNumber == 1) {

            getSprite().setTexture(animation2);
            animationNumber = 2;

        } else {

            getSprite().setTexture(animation1);
            animationNumber = 1;

        }

        clock.restart();

    }
}
