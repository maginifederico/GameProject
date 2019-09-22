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

void Checkpoint::interact(GameHero *player, Map &map, int i) {


    //SCRITTA CHECKPOINT SULLO SCHERMO
    //SETTARE IL RESPAWN QUI

    getSprite().setTexture(animation1);
    animationNumber = 1;
    map.getObjectsCollector().erase(map.getObjectsCollector().begin() + i);

    //Aggiungi la bandierina agli oggetti animati
    map.getAnimatedObjects().push_back(this);


}

void Checkpoint::updateAnimation() {


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
