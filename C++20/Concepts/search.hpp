#include <vector>
#include <math.h>

#include "comparable.hpp"

template<typename T> requires Comparable<T>
constexpr int binary_search(const std::vector<T>* input, const T elem)
{
    int l, r;
    l = 0;
    r = input->size() - 1;

    while (l <= r)
    {
        int m = std::floor((l + r) / 2);

        if (input->at(m) < elem)
            l = m + 1;
        else if (input->at(m) > elem)
            r = m - 1;
        else return m;
    }
    return -1;
}