/**
 * Project Untitled
 */


#include "WalkingBehaviour.h"

/**
 * WalkingBehaviour implementation
 */

WalkingBehaviour::WalkingBehaviour(bool dir) {
    rightDirection = dir;

    if (!rightTextureDirection.loadFromFile(rightTexturePath))
        std::cout << "Unable to load the sprite";

    if (!leftTextureDirection.loadFromFile(leftTexturePath))
        std::cout << "Unable to load the sprite";
}


void WalkingBehaviour::updatePosition(Map &map, GameCharacter &enemy) {

    int c = (int) enemy.getSprite().getPosition().x / 21;
    int r = (int) enemy.getSprite().getPosition().y / 21;
    int left = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21)].getId();
    int right = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1].getId();
    int down_left = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + int(map.getWidth() / 21)].getId();
    int down_right = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + int(map.getWidth() / 21) +
                                                 1].getId();
    int water = 48;
    int waterSurface = 49;
    int groundSurface1 = 34;
    int groundSurface2 = 47;
    int groundSurface3 = 42;
    int platform1 = 43;
    int platform2 = 44;
    int ground1 = 36;
    int ground2 = 40;
    int ground3 = 139;
    int aria = 0;

    if (rightDirection) {
        if ((down_right == groundSurface1 || down_right == ground1 || down_right == groundSurface2 ||
             down_right == platform1 || down_right == platform2 || down_right == groundSurface3) && right == aria)
            enemy.getSprite().move(enemy.getSpeed(), 0.f);
        else {
            rightDirection = false;
            enemy.getSprite().setTexture(leftTextureDirection);
        }
    } else {
        if ((down_left == groundSurface1 || down_left == ground1 || down_left == groundSurface2 ||
             down_left == platform1 || down_left == platform2 || down_left == groundSurface3) && left == aria)
            enemy.getSprite().move(-enemy.getSpeed(), 0.f);
        else {
            rightDirection = true;
            enemy.getSprite().setTexture(rightTextureDirection);
        }
    }


}

void WalkingBehaviour::attack() {

}