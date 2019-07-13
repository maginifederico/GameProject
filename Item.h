/**
 * Project Untitled
 */


#ifndef _ITEM_H
#define _ITEM_H

class Item {
public:
    float posX;
    float posY;
    int coinValue;
    int pillValue;
    int shieldValue;
    int attackValue;
    float shieldTimer;
    float attackTimer;

    void virtual collect();
};

#endif //_ITEM_H