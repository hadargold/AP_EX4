#ifndef SERVERAPPLICATION_ISEARCHER_H
#define SERVERAPPLICATION_ISEARCHER_H

#include "ISearchable.h"
#include "State.h"
#include <string>

using std::string;

namespace server_side {

    class ISearcher {

    public:

        virtual SearchAlgo search(ISearchable *searchable) = 0;

        virtual ~ISearcher() = default;

    };
}

#endif //SERVERAPPLICATION_ISEARCHER_H
