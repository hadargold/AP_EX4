//
// Created by hadar on 1/21/20.
//
#ifndef SERVERAPPLICATION_MATRIX_H
#define SERVERAPPLICATION_MATRIX_H

#include "ISearchable.h"

using std::vector;

namespace server_side {
    
    class Matrix : public ISearchable {
        
        State *initialState;
        State *goalState;

    public:

        vector<vector<State>> matrix;

        Matrix(vector<vector<int>> givenMatrix, std::pair<int, int> src, std::pair<int, int> dst);

        State *getInitialState() override;

        State *getGoalState() override;

        vector<State *> getAllPossibleStates(State *s) override;

    };

}


#endif //SERVERAPPLICATION_MATRIX_H
