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

    QueueElmt<T> *dequeue()
    {
        if (this->getSize() != 0)
        {
            QueueElmt<T> *node;
            node = this->getHead();
            this->removeHead();
            return node;
        }
        else
        {
            return nullptr;
        }
    }

    QueueElmt<T> *peek()
    {
        if (this->getSize() != 0)
        {
            QueueElmt<T> *node;
            node = this->getHead();
            return node;
        }
        else
        {
            return nullptr;
        }
    }
};

#endif