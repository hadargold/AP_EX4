//
// Created by hadar on 1/23/20.
//
#include <iostream>
#include "DFS.h"

server_side::SearchAlgo server_side::DFS::search(server_side::ISearchable *searchable) {

    searchAlgo.developedVertices = 0;
    searchAlgo.shortestPathRoute = "";
    searchAlgo.shortestPathWeight = 0;

    goalState = searchable->getGoalState();
    recursiveSearch(searchable->getInitialState());
    return this->searchAlgo;

}

bool server_side::DFS::recursiveSearch(server_side::State* currentState){

    if (currentState->isInfinity || currentState->isMarked || currentState == NULL)
        return false;
    this->searchAlgo.shortestPathWeight += currentState->weigth;

    searchAlgo.developedVertices++;

    if(currentState == goalState) return true;

    currentState->isMarked = true;

    if (currentState->left!=NULL && recursiveSearch(currentState->left))
    {
        this->searchAlgo.shortestPathRoute.insert(0, "Left, ");
        return true;
    }

    if (currentState->top!=NULL && recursiveSearch(currentState->top))
    {
        this->searchAlgo.shortestPathRoute.insert(0, "Up, ");
        return true;
    }

    if (currentState->right!=NULL && recursiveSearch(currentState->right))
    {
        this->searchAlgo.shortestPathRoute.insert(0, "Right, ");
        return true;
    }

    if (currentState->bottom!=NULL && recursiveSearch(currentState->bottom))
    {
        this->searchAlgo.shortestPathRoute.insert(0, "Down, ");
        return true;
    }

    this->searchAlgo.shortestPathWeight -= currentState->weigth;

    return false;
}

