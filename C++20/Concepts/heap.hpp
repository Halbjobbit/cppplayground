#include "comparable.hpp"

#include <iostream>
#include <algorithm>

template <typename T>
requires Comparable<T> class max_heap
{
private:
    T *m_arr;
    int m_max_size;
    int m_size;

public:
    max_heap(int max_size)
    {
        m_max_size = max_size;
        m_size = 0;
        m_arr = new T[m_max_size];
    }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    bool insert(T elem)
    {
        if (m_size == m_max_size)
        {
            return false;
        }

        m_size++;
        int i = m_size - 1;
        m_arr[i] = elem;

        while (i != 0 && m_arr[parent(i)] < m_arr[i])
        {
            std::swap(m_arr[i], m_arr[parent(i)]);
            i = parent(i);
        }

        return true;
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < m_size && m_arr[l] > m_arr[i])
            smallest = l;
        if (r < m_size && m_arr[r] > m_arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            std::swap(m_arr[i], m_arr[smallest]);
            heapify(smallest);
        }
    }

    T extract_max()
    {
        if (m_size == 1)
        {
            m_size--;
            return m_arr[0];
        }

        T root = m_arr[0];
        m_arr[0] = m_arr[m_size - 1];
        m_size--;
        heapify(0);

        return root;
    }
};
