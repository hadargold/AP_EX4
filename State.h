#ifndef SERVERAPPLICATION_STATE_H
#define SERVERAPPLICATION_STATE_H

#include <string>
#include <vector>

namespace server_side {
    enum Direction {

        NotSet = 0,
        Start = 1,
        Left = 2,
        Up = 3,
        Right = 4,
        Down = 5,

    };
}

namespace server_side {

    class State
    {

    public:

        State *top;
        State *bottom;
        State *left;
        State *right;

        int weigth;
        bool isInfinity;
        bool isMarked;
        Direction commingFrom;
        unsigned int row_index;
        unsigned int col_index;

        State(int weigth) : top(NULL), bottom(NULL), left(NULL), right(NULL), weigth(weigth), isMarked(false) {}

        std::vector<State *> getNeighbors() {
            std::vector<State *> ret;

            if (bottom != NULL)
                ret.push_back(bottom);
            if (top != NULL)
                ret.push_back(top);
            if (left != NULL)
                ret.push_back(left);
            if (right != NULL)
                ret.push_back(right);
            return ret;
        }

    };


    struct SearchAlgo {

        std::string shortestPathRoute;

        int shortestPathWeight;

        int developedVertices;

    };

}

#endif //SERVERAPPLICATION_STATE_H
