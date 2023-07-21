#ifndef __CHTBL_HPP__
#define __CHTBL_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"

template <typename T, typename H1, typename H2>
class OAHTbl
{
public:
    OAHTbl(const unsigned int positions) : size(0), positions(positions), vacated(nullptr), tbl(new T *[positions]) {}
    OAHTbl(const unsigned int positions, T *vacated) : size(0), positions(positions), vacated(vacated), tbl(new T *[positions]) {}
    void insert(T data)
    {
        if (!lookup(data))
        {
            int position, i;

            for (i = 0; i < positions; i++)
            {
                position = h(&data, i);

                if (!tbl[position] || tbl[position] == vacated)
                {
                    tbl[position] = &data;
                    size += 1;
                    break;
                }
            }
        }
    }
    bool lookup(T data)
    {
        int position, i;

        for (i = 0; i < positions; i++)
        {
            position = h(&data, i);

            if (!tbl[position])
            {
                break;
            }
            else if (match(*tbl[position], data))
            {
                return true;
            }
        }

        return false;
    }
    void remove(T data)
    {
        int position, i;

        for (i = 0; i < positions; i++)
        {
            position = h(&data, i);

            if (!tbl[position])
            {
                break;
            }
            else if (tbl[position] == vacated)
            {
                continue;
            }
            else if (match(*tbl[position], data))
            {
                tbl[position] = vacated;
                size -= 1;
            }
        }
    }
    const int getSize() { return size; }
    const unsigned int getPositions() { return positions; }
    inline bool match(T lhs, T rhs)
    {
        return lhs == rhs ? true : false;
    }
    void display()
    {
        for (int i = 0; i < positions; i++)
        {
            if (tbl[i])
            {
                std::cout << "tbl[" << i << "] = " << *(tbl[i]) << std::endl;
            }
        }
    }

private:
    inline unsigned int h(const void *key, int i)
    {
        return (h1(key) + i * h2(key)) % positions;
    }
    const unsigned int positions;
    int size;
    T **tbl;
    T *vacated;
    H1 h1;
    H2 h2;
};

#endif