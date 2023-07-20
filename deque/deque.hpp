#ifndef __DEQUE_HPP__
#define __DEQUE_HPP__

#include <iostream>

#include "../doublylinkedlist/doublylinkedlist.hpp"

template <typename T>
using DequeElmt = DLListElmt<T>;

template <typename T>
class Deque : private DLList<T>
{
public:
    const int getSize() { return this->size; }
    void push_front(T data)
    {
        this->insertHead(data);
    }
    void push_back(T data)
    {
        this->insertTail(data);
    }
    DequeElmt<T> *peek_front()
    {
        return this->getHead();
    }
    DequeElmt<T> *peek_back()
    {
        return this->getTail();
    }
    DequeElmt<T> *pop_front()
    {
        DequeElmt<T> *node = new DequeElmt<T>;
        *node = *this->getHead();
        if (node)
        {
            this->removeHead();
        }
        return node;
    }
    DequeElmt<T> *pop_back()
    {
        DequeElmt<T> *node = new DequeElmt<T>;
        *node = *this->getTail();
        if (node)
        {
            this->removeTail();
        }
        return node;
    }
};

#endif