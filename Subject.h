//
// Created by sode on 16/10/19.
//

#ifndef GAME_SUBJECT_H
#define GAME_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {

public:


    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;

};


#endif //GAME_SUBJECT_H
