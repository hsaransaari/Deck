#pragma once

#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>

// Implements Deck as specified using std::vector.

template<typename T>
class Deck : public std::vector<T>
{
public:
    T top() const
    {
        assert(!this->empty());
        return this->back();
    }

    T bottom() const
    {
        assert(!this->empty());
        return this->front();
    }

    T draw()
    {
        assert(!this->empty());
        T ret = top();
        this->pop_back();
        return ret;
    }

    void add(T v)
    {
        this->push_back(v);
    }

    void shuffle(int seed)
    {
        std::shuffle(this->begin(), this->end(), std::default_random_engine(seed));
    }
};
