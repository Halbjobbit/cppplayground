#include <algorithm>
#include <vector>

#include "comparable.hpp"

template<typename T> requires Comparable<T>
constexpr void bubble_sort(std::vector<T>* input)
{
    for (int i = 0; i < (input->size() - 1); i++)
		for (int j = 0; j < (input->size() - i - 1); j++)
			if (input->at(j) > input->at(j + 1))
				std::swap(input->at(j), input->at(j + 1));
}