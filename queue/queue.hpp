#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

#include "../linkedlist/linkedlist.hpp"

template <typename T>
using QueueElmt = LListElmt<T>;

template <typename T>
class Queue : private LList<T>
{
public:
    const int getSize() { return this->size; }
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
        QueueElmt<T> *node = new QueueElmt<T>(this->getHead()->getData());

        if (node)
        {
            this->removeHead();
        }

        return node;
    }
};

#endif