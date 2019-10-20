//
// Created by sode on 18/10/19.
//

#include "State.h"

State::State() : stateChanged(true) {

}

bool State::isStateChanged() const {
    return stateChanged;
}

void State::setStateChanged(bool s) {
    stateChanged = s;
}
