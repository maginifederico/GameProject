/**
 * Project Untitled
 */


#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon {
public:
    int damage;
    float range;
    int cooldown;
    int level;
    float explosionRange;

    void shoot();
};

#endif //_WEAPON_H