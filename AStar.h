//
// Created by hadar on 1/23/20.
//

#ifndef SERVERAPPLICATION_ASTARBLOG_H
#define SERVERAPPLICATION_ASTARBLOG_H

#include "ISearcher.h"
#include <map>

namespace server_side {


    class AStar : public ISearcher {

        SearchAlgo searchAlgo;

    public:
        SearchAlgo search(ISearchable *searchable) override;
    };
}

#endif //SERVERAPPLICATION_ASTARBLOG_H
