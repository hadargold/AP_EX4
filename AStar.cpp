//
// Created by hadar on 1/23/20.
//

#include <queue>
#include <algorithm>
#include <iostream>
#include "AStar.h"
#include "PriorityQueue.h"

namespace server_side {
    inline int heuristic(State *a, State *b) {
        return std::abs((int) (a->row_index - b->row_index)) + std::abs(((int) (a->col_index - b->col_index)));
    }

    server_side::SearchAlgo server_side::AStar::search(server_side::ISearchable *searchable) {
        searchAlgo.developedVertices = 0;
        searchAlgo.shortestPathRoute = "";
        searchAlgo.shortestPathWeight = 0;

        auto start = searchable->getInitialState();
        auto goal = searchable->getGoalState();
        
        std::map<State *,  State *> cameFrom;

        std::map<State *, int> costTillNow;
        
        PriorityQueue<State *, int> frontier;
        frontier.put(start, 0);

        cameFrom[start] = start;
        costTillNow[start] = 0;

        State *current = NULL;

        while (!frontier.empty()) {
            current = frontier.get();
            
            if (current == goal) {
                break;
            }

            for (State *next : current->getNeighbors()) {
                if (next->isInfinity)
                    continue;
                int new_cost = costTillNow[current] + next->weigth;
                if (costTillNow.find(next) == costTillNow.end()
                    || new_cost < costTillNow[next]) {
                    costTillNow[next] = new_cost;
                    int priority = new_cost + heuristic(next, goal);
                    frontier.put(next, priority);
                    cameFrom[next] = current;
                    searchAlgo.developedVertices++;
                }
            }

        }

        std::vector<State *> path;
        if (current != goal){
            searchAlgo.shortestPathRoute = "";
            searchAlgo.shortestPathWeight = -1;
            return searchAlgo;
        }


        while (current != start) {


            path.push_back(current);
            current = cameFrom[current];
            searchAlgo.shortestPathWeight += current->weigth;
        }

        path.push_back(start); // optional
        std::reverse(path.begin(), path.end());


        std::string step;

        auto it = path.begin();
        for (; it != path.end() && it + 1 != path.end(); it++){

            //went right
            if ((*(it+1))->col_index > (*(it))->col_index) {
                step = "Right, ";
            }
            //went left
            if ((*(it+1))->col_index < (*(it))->col_index)
                step = "Left, ";
            //down
            if ((*(it+1))->row_index > (*(it))->row_index)
                step = "Down, ";
            //up
            if((*(it+1))->row_index < (*(it))->row_index)
                step = "Up, ";

            searchAlgo.shortestPathRoute.append(step);

        }

        searchAlgo.shortestPathRoute =
                searchAlgo.shortestPathRoute.substr(0, searchAlgo.shortestPathRoute.length() - 2);
        return searchAlgo;

    }
}
