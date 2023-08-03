#ifndef __QKSORT_HPP__
#define __QKSORT_HPP__

#include <iostream>
#include "../sort.hpp"
#include "../issort/issort.hpp"

template <typename T, typename F>
int partition(T *data, int i, int k, F f)
{
    T pval, tmp;

    int r[3];
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;

    CompareT<T> c;
    issort(r, 3);
    pval = data[r[1]];

    while (true)
    {
        while (f(data[k], pval))
        {
            k--;
        }
        while (f(pval, data[i]))
        {
            i++;
        }
        if (i >= k)
        {
            break;
        }
        else
        {
            tmp = data[i];
            data[i] = data[k];
            data[k] = tmp;
        }
    }

    return k;
}

template <typename T, typename F>
void qksort(T *data, int i, int k, F f)
{
    int j;
    while (i < k)
    {
        j = partition(data, i, k, f);
        qksort(data, i, j, f);
        i = j + 1;
    }
}

template <typename T, typename F>
void qksort(T *data, int size, F f)
{
    qksort(data, 0, size - 1, f);
}

#endif