#ifndef SERVERAPPLICATION_SEARCHSOLVER_H
#define SERVERAPPLICATION_SEARCHSOLVER_H

#include <string>
#include "ISolver.h"
#include "ISearcher.h"

using std::string;

namespace server_side {
    
class SearchSolver : public ISolver<ISearchable *, SearchAlgo> {

        ISearcher *searcher;
        
    public:

        SearchSolver(ISearcher *searcher) : searcher(searcher) {}

        SearchAlgo solve(ISearchable *p) override {
            return searcher->search(p);
        }

    ~SearchSolver() override {
        delete(searcher);
    }

};
};

#endif //SERVERAPPLICATION_SEARCHSOLVER_H
