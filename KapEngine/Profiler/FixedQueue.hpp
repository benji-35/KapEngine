#ifndef RTYPE_FIXEDQUEUE_HPP
#define RTYPE_FIXEDQUEUE_HPP

#include <queue>
#include <deque>
#include <iostream>

template <typename A, int MaxSize, typename B=std::deque<A>>
class FixedQueue : public std::queue<A, B> {
public:

    void push(const A &v) {
        if (this->size() == MaxSize) {
            this->c.pop_front();
        }
        std::queue<A, B>::push(v);
    }

};

#endif //RTYPE_FIXEDQUEUE_HPP
