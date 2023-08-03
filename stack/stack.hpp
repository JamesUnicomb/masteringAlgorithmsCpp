#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>

#include "../linkedlist/linkedlist.hpp"

template <typename T>
using StackElmt = LListElmt<T>;

template <typename T>
class Stack : private LList<T>
{
public:
    const int getSize() { return this->size; }
    void push(T data)
    {
        this->insertHead(data);
    }
    StackElmt<T> *peek()
    {
        return this->getHead();
    }
    StackElmt<T> *pop()
    {
        StackElmt<T> *node = new StackElmt<T>(this->getHead()->getData());

        if (node)
        {
            this->removeHead();
        }
        return node;
    }
};

#endif