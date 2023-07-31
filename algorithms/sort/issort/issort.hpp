#ifndef __ISSORT_HPP__
#define __ISSORT_HPP__

#include "../sort.hpp"

template <typename T, typename F>
void issort(T *data, int size, F f)
{
    T key;

    int i, j;

    for (j = 1; j < size; j++)
    {
        key = data[j];
        i = j - 1;

        while (i >= 0 && f(data[i], key))
        {
            data[i + 1] = data[i];
            i--;
        }

        data[i + 1] = key;
    }
}

template <typename T>
void issort(T *data, int size)
{
    CompareT<T> c;
    issort(data, size, c);
}

#endif