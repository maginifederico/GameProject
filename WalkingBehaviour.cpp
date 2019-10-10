/**
 * Project Untitled
 */


#include "WalkingBehaviour.h"
#include "Enemy.h"

/**
 * WalkingBehaviour implementation
 */

WalkingBehaviour::WalkingBehaviour(Direction dir) {
    direction = dir;

    if (!rightTextureDirection.loadFromFile(rightTexturePath))
        std::cout << "Unable to load the sprite";

    if (!leftTextureDirection.loadFromFile(leftTexturePath))
        std::cout << "Unable to load the sprite";
}


void WalkingBehaviour::updatePosition(Map &map, Enemy &enemy) {

    int c = (int) enemy.getSprite().getPosition().x / 21;
    int r = (int) enemy.getSprite().getPosition().y / 21;
    int leftTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21)].getId();
    int rightTile = map.getLayer()[1].getTile()[c + r * int(map.getWidth() / 21) + 1].getId();
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

    if (direction == right) {
        if ((down_right == groundSurface1 || down_right == ground1 || down_right == groundSurface2 ||
             down_right == platform1 || down_right == platform2 || down_right == groundSurface3) && rightTile == aria)
            enemy.getSprite().move(enemy.getSpeed(), 0.f);
        else {
            direction = left;
            enemy.getSprite().setTexture(leftTextureDirection);
        }
    } else {
        if ((down_left == groundSurface1 || down_left == ground1 || down_left == groundSurface2 ||
             down_left == platform1 || down_left == platform2 || down_left == groundSurface3) && leftTile == aria)
            enemy.getSprite().move(-enemy.getSpeed(), 0.f);
        else {
            direction = right;
            enemy.getSprite().setTexture(rightTextureDirection);
        }
    }


}

void WalkingBehaviour::attack() {

    int a;

}