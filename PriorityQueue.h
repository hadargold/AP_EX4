//
// Created by yuval on 1/23/20.
//

#ifndef SERVERAPPLICATION_PRIORITYQUEUE_H
#define SERVERAPPLICATION_PRIORITYQUEUE_H


#include <queue>
using namespace std;

namespace server_side {

    template<typename T, typename priority_t>
    struct PriorityQueue {
        typedef pair<priority_t, T> elementForPriorityQueue;
        // <class, container, compare>
        priority_queue<elementForPriorityQueue, vector<elementForPriorityQueue>,
                greater<elementForPriorityQueue>> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(T item, priority_t priority) {
            elements.emplace(priority, item);
        }

        T get() {
            T best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

}


#endif //SERVERAPPLICATION_PRIORITYQUEUE_H
