#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>

#include "../linkedlist/linkedlist.hpp"

template <typename T>
using StackElmt = LListElmt<T>;

template <typename T>
class Stack : public LList<T>
{
public:
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
        StackElmt<T> *node = this->getHead();
        if (node)
        {
            this->removeHead();
        }
        return node;
    }
};

#endif