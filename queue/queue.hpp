#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

#include "../linkedlist/linkedlist.hpp"

template <typename T>
using QueueElmt = LListElmt<T>;

template <typename T>
class Queue : public LList<T>
{
public:
    void enqueue(T data)
    {
        this->insertTail(data);
    }
    QueueElmt<T> *peek()
    {
        return this->getHead();
    }
    QueueElmt<T> *dequeue()
    {
        QueueElmt<T> *node = this->getHead();
        if (node)
        {
            this->removeHead();
        }
        return node;
    }
};

#endif