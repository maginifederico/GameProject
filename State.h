//
// Created by sode on 18/10/19.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H


class State {

public:

    State();

    virtual State *getNextState() = 0;

    bool isStateChanged() const;

    void setStateChanged(bool stateChanged);

private:
    bool stateChanged;

};


#endif //GAME_STATE_H
