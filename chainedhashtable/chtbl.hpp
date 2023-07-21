#ifndef __CHTBL_HPP__
#define __CHTBL_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"

template <typename T, typename H>
class CHTbl
{
public:
    CHTbl(const unsigned int buckets) : size(0), buckets(buckets), tbl(new LList<T>[buckets]) {}
    void insert(T data)
    {
        if (!lookup(data))
        {
            tbl[h(&data) % buckets].insertHead(data);
            size += 1;
        }
    }
    bool lookup(T data)
    {
        LListElmt<T> *node = tbl[h(&data) % buckets].getHead();

        while (node)
        {
            if (data == node->getData())
            {
                return true;
            }
            node = node->getNext();
        }

        return false;
    }
    void remove(T data)
    {
        if (lookup(data))
        {
            LList<T> *list = &tbl[h(&data) % buckets];
            LListElmt<T> *node = list->getHead(), *prev = nullptr;

            while (node)
            {
                if (data == node->getData())
                {
                    if (prev)
                    {
                        list->removeNext(prev);
                    }
                    else
                    {
                        list->removeHead();
                    }
                    size -= 1;
                }
                prev = node;
                node = node->getNext();
            }
        }
    }
    const int getSize() { return size; }
    const unsigned int getBuckets() { return buckets; }
    inline bool match(T lhs, T rhs)
    {
        return lhs == rhs ? true : false;
    }
    void display()
    {
        for (int i = 0; i < buckets; i++)
        {
            tbl[i].display();
        }
    }

private:
    const unsigned int buckets;
    int size;
    LList<T> *tbl;
    H h;
};

#endif