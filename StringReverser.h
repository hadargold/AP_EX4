//
// Created by yuval on 1/20/20.
//

#ifndef SERVERAPPLICATION_STRINGREVERSER_H
#define SERVERAPPLICATION_STRINGREVERSER_H

#include <string>
#include <bits/stdc++.h>
#include "ISolver.h"
#include <algorithm>

namespace server_side{

    class StringReverser : public ISolver<std::string, std::string>{
    public:
        std::string solve(std::string p) override {
            reverse(p.begin(), p.end());
            return p;
        }
    };

}

#endif //SERVERAPPLICATION_STRINGREVERSER_H
