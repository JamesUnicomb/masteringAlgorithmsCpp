#ifndef __SET_HPP__
#define __SET_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../trees/binarytree/binarytree.hpp"

template <typename T>
class Set
{
public:
    Set() : tree() {}
    void insert(T data)
    {
        tree.insert(data);
    }
    void remove(T data)
    {
        tree.remove(data);
    }
    int getSize()
    {
        return tree.getSize();
    }
    bool find(T data)
    {
        return tree.find(data) ? true : false;
    }
    void display()
    {
        LList<T> *list = tree.toList();
        LListElmt<T> *node = list->getHead();
        std::cout << "{";
        while (node)
        {
            std::cout << node->getData();
            if (node->getNext())
                std::cout << ",";
            node = node->getNext();
        }
        std::cout << "}" << std::endl;
    }
    LList<T> *toList()
    {
        return tree.toList();
    }

private:
    Tree<T> tree;
};

template <typename T>
Set<T> setIntersection(Set<T> a, Set<T> b)
{
    Set<T> c;
    int n = a.getSize(), m = b.getSize();

    if (n < m)
    {
        LListElmt<T> *node = a.toList()->getHead();

        while (node)
        {
            if (b.find(node->getData()))
            {
                c.insert(node->getData());
            }
            node = node->getNext();
        }
    }
    else
    {
        LListElmt<T> *node = b.toList()->getHead();

        while (node)
        {
            if (a.find(node->getData()))
            {
                c.insert(node->getData());
            }
            node = node->getNext();
        }
    }

    return c;
}

template <typename T>
Set<T> setUnion(Set<T> a, Set<T> b)
{
    Set<T> c;

    LListElmt<T> *node = a.toList()->getHead();

    while (node)
    {
        c.insert(node->getData());
        node = node->getNext();
    }

    node = b.toList()->getHead();

    while (node)
    {
        c.insert(node->getData());
        node = node->getNext();
    }

    return c;
}

#endif