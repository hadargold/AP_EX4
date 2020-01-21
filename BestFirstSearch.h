#ifndef SERVERAPPLICATION_BESTFIRSTSEARCH_H
#define SERVERAPPLICATION_BESTFIRSTSEARCH_H

#include "ISearcher.h"

namespace server_side {

    class BestFirstSearch : public ISearcher {

    public:
        SearchAlgo search(ISearchable *searchable) override;

    };
}

#endif //SERVERAPPLICATION_BESTFIRSTSEARCH_H
