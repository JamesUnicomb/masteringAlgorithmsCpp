#ifndef __MGSORT_HPP__
#define __MGSORT_HPP__

#include "../sort.hpp"

template <typename T, typename F>
void merge(T *data, int i, int j, int k, F f)
{
    T *m = new T[(k - i) + 1];

    int ipos, jpos, mpos;

    ipos = i;
    jpos = j + 1;
    mpos = 0;

    while (ipos <= j || jpos <= k)
    {
        if (ipos > j)
        {
            while (jpos <= k)
            {
                m[mpos] = data[jpos];
                jpos++;
                mpos++;
            }
            continue;
        }
        else if (jpos > k)
        {
            while (ipos <= j)
            {
                m[mpos] = data[ipos];
                ipos++;
                mpos++;
            }
            continue;
        }

        if (f(data[jpos], data[ipos]))
        {
            m[mpos] = data[ipos];
            ipos++;
            mpos++;
        }
        else
        {
            m[mpos] = data[jpos];
            jpos++;
            mpos++;
        }
    }

    memcpy(data + i, m, sizeof(T) * (k - i + 1));

    delete[] m;
}

template <typename T, typename F>
void mgsort(T *data, int i, int k, F f)
{
    int j;

    if (i < k)
    {
        j = (int)((i + k - 1) / 2);
        mgsort(data, i, j, f);
        mgsort(data, j + 1, k, f);
        merge(data, i, j, k, f);
    }
}

#endif