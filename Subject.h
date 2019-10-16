//
// Created by sode on 16/10/19.
//

#ifndef GAME_SUBJECT_H
#define GAME_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {

public:
    void subscribe(Observer *o);

    void unsubscribe(Observer *o);

    void notify();

protected:

    std::vector<Observer *> observers;

};


#endif //GAME_SUBJECT_H
