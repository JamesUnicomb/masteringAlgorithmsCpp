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

    StackElmt<T> *pop()
    {
        if (this->getSize() != 0)
        {
            StackElmt<T> *node;
            node = this->getHead();
            this->removeHead();
            return node;
        }
        else
        {
            return nullptr;
        }
    }

    StackElmt<T> *peek()
    {
        if (this->getSize() != 0)
        {
            StackElmt<T> *node;
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