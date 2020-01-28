//
// Created by hadar on 1/23/20.
//
#ifndef SERVERAPPLICATION_BFS_H
#define SERVERAPPLICATION_BFS_H


#include "ISearcher.h"
#include <queue>

namespace server_side {


    class BFS : public ISearcher {

    public:
        SearchAlgo search(ISearchable *searchable) override;
    };
}

#endif //SERVERAPPLICATION_BFS_H
