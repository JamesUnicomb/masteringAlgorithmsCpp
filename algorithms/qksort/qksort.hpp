#ifndef __QKSORT_HPP__
#define __QKSORT_HPP__

#include <iostream>

template <typename T, typename F>
int partition(T *data, int i, int k, F f)
{
    T pval, tmp;

    int r[3];
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;

    int jtmp;
    if (r[0] > r[1])
    {
        jtmp = r[1];
        r[1] = r[0];
        r[0] = jtmp;
    }

    if (r[1] > r[2])
    {
        jtmp = r[2];
        r[2] = r[1];
        r[1] = jtmp;
    }

    if (r[0] > r[1])
    {
        jtmp = r[1];
        r[1] = r[0];
        r[0] = jtmp;
    }

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

#endif