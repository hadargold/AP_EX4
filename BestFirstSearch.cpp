#include <queue>
#include "BestFirstSearch.h"
#include "MatrixGraph.h"

using namespace std;

class Compare
{
public:
    bool operator() (server_side::State *a, server_side::State *b)
    {
        return a->weigth > b->weigth;
    }
};

server_side::SearchAlgo server_side::BestFirstSearch::search(server_side::ISearchable *searchable) {

    SearchAlgo searchAlgo;

    searchAlgo.developedVertices = 0;
    searchAlgo.shortestPathRoute = "";
    searchAlgo.shortestPathWeight = 0;
    State* goalState;
    goalState = searchable->getGoalState();

    priority_queue<State *, std::vector<State *>, Compare> priorityQueue;

    searchable->getInitialState()->commingFrom = Start;

    priorityQueue.push((searchable->getInitialState()));

    State *current_node;
    while (!priorityQueue.empty())
    {
        current_node = priorityQueue.top();
        priorityQueue.pop();

        if (current_node == goalState) //finished
        {
            break;
        }

        //top
        if (current_node->top != NULL && !current_node->top->isInfinity && current_node->top->commingFrom == NotSet)
        {
            current_node->top->commingFrom = Down;
            priorityQueue.push(current_node->top);

        }

        //bottom
        if (current_node->bottom != NULL && !current_node->bottom->isInfinity && current_node->bottom->commingFrom == NotSet)
        {
            current_node->bottom->commingFrom = Up;
            priorityQueue.push(current_node->bottom);
        }
        //left
        if (current_node->left != NULL && !current_node->left->isInfinity && current_node->left->commingFrom == NotSet)
        {
            current_node->left->commingFrom = Right;
            priorityQueue.push(current_node->left);
        }
        //right
        if (current_node->right != NULL && !current_node->right->isInfinity && current_node->right->commingFrom == NotSet)
        {
            current_node->right->commingFrom = Left;
            priorityQueue.push(current_node->right);
        }

        searchAlgo.developedVertices++;
    }

    //no path exists!
    if (current_node != goalState){
        searchAlgo.shortestPathRoute = "";
        searchAlgo.shortestPathWeight = -1;
        return searchAlgo;
    }


    bool arrivedStart = false;

    string currentDir;
    while (!arrivedStart)
    {

        searchAlgo.shortestPathWeight += current_node->weigth;
        switch (current_node->commingFrom)
        {
            case Up:
                current_node = current_node->top;
                currentDir = "Down, ";
                break;
            case Down:
                current_node = current_node->bottom;
                currentDir = "Up, ";
                break;
            case Left:
                current_node = current_node->left;
                currentDir = "Right, ";
                break;
            case Right:
                current_node = current_node->right;
                currentDir = "Left, ";
                break;
            case Start:
                arrivedStart = true;
                break;
            default:
                throw "not valid scenario";
        }
        if (!arrivedStart)
            searchAlgo.shortestPathRoute.insert(0, currentDir);
    }
    searchAlgo.shortestPathRoute =
            searchAlgo.shortestPathRoute.substr(0, searchAlgo.shortestPathRoute.length() - 2);

    return searchAlgo;
}
