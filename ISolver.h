#ifndef SERVERAPPLICATION_SOLVER_H
#define SERVERAPPLICATION_SOLVER_H

namespace server_side {

    // P- problem , S- solution
    template <class P, class S>
    class ISolver {

    public:

        virtual S solve(P) = 0;

        virtual ~ISolver() = default;

    };
}

#endif //SERVERAPPLICATION_SOLVER_H
