//
// Created by hadar on 1/23/20.
//
#ifndef SERVERAPPLICATION_DFS_H
#define SERVERAPPLICATION_DFS_H

#include "ISearcher.h"

namespace server_side {

    class DFS : public ISearcher {

        SearchAlgo searchAlgo;
        State* goalState;

    public:

        SearchAlgo search(ISearchable *searchable) override;
        bool recursiveSearch(State* currentState);

    };
}

#endif //SERVERAPPLICATION_DFS_H
