//
// Created by yuval on 1/20/20.
//
#ifndef SERVERAPPLICATION_ISEARCHABLE_H
#define SERVERAPPLICATION_ISEARCHABLE_H

#include <vector>
#include "State.h"

namespace server_side {

    using std::vector;

    class ISearchable {

    public:

        virtual State *getInitialState() = 0;

        virtual State *getGoalState() = 0;

        virtual std::vector<State *> getAllPossibleStates(State *s) = 0;

    };
}

#endif //SERVERAPPLICATION_ISEARCHABLE_H
