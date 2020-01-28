//
// Created by hadar on 1/21/20.
//
#include "Matrix.h"

server_side::Matrix::Matrix(vector<vector<int>> givenMatrix, std::pair<int, int> src,
                            std::pair<int, int> dst) : matrix(givenMatrix.size(), vector<State>(givenMatrix[0].size(), State(0))) {

    int rowsSize = givenMatrix.size();
    int colsSize = givenMatrix[0].size();

    //building the basic matrix
    for (int i = 0; i < rowsSize; ++i) {
        for (int j = 0; j < colsSize; ++j) {
            int currentWeigth = givenMatrix[i][j];
            matrix[i][j].weigth = currentWeigth;
        }
    }

    //init all the state with values
    for (int i = 0; i < rowsSize; ++i) {

        for (int j = 0; j < colsSize; ++j) {

            State* currentState = &matrix[i][j];

            currentState->commingFrom = NotSet;

            currentState->isMarked = false;

            currentState->isInfinity = currentState->weigth == -1 ? true : false;

            //up != null
            currentState->top = i != 0 ? &matrix[i-1][j] : NULL;

            //bottom != null
            currentState->bottom = i != (rowsSize-1) ? &matrix[i+1][j] : NULL;

            //left != null
            currentState->left = j != 0 ? &matrix[i][j-1] : NULL;

            //right != null
            currentState->right = j != (colsSize-1) ? &matrix[i][j+1] : NULL;

            currentState->row_index = i;
            currentState->col_index = j;

            //this is the start state
            if(i == src.first && j == src.second){
                initialState = &matrix[i][j];
            }

            //this is the end state
            if(i == dst.first && j == dst.second){
                goalState = &matrix[i][j];
            }

        }

    }

    int a = 0;

}


server_side::State *server_side::Matrix::getInitialState() {
    return this->initialState;
}

server_side::State *server_side::Matrix::getGoalState() {
    return this->goalState;
}

std::vector<server_side::State *> server_side::Matrix::getAllPossibleStates(server_side::State *s) {
    return s->getNeighbors();
}


