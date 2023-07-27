#ifndef __SET_HPP__
#define __SET_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../trees/binarytree/binarytree.hpp"

template <typename T>
using SetElmt = TreeNode<T>;

template <typename T>
class Set
{
public:
    Set() : tree() {}
    SetElmt<T> *begin() { return tree.begin(); }
    SetElmt<T> *end() { return tree.end(); }
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
    SetElmt<T> *find(T data)
    {
        return tree.find(data);
    }
    void display()
    {
        typename Tree<T>::iterator it;
        SetElmt<T> *node = tree.begin(), *next;

        std::cout << "{";
        while (next = it.next(node))
        {
            std::cout << node->getData();
            std::cout << ",";
            node = next;
        }
        std::cout << node->getData();
        std::cout << "}" << std::endl;
    }

private:
    Tree<T> tree;
};

template <typename T>
Set<T> setIntersection(Set<T> &a, Set<T> &b)
{
    Set<T> c;
    typename Tree<T>::iterator it;

    int n = a.getSize(), m = b.getSize();

    if (n < m)
    {
        SetElmt<T> *node = a.begin();

        while (node != a.end())
        {
            if (b.find(node->getData()))
            {
                c.insert(node->getData());
            }
            node = it.next(node);
        }
    }
    else
    {
        SetElmt<T> *node = b.begin();

        while (node != b.end())
        {
            if (a.find(node->getData()))
            {
                c.insert(node->getData());
            }
            node = it.next(node);
        }
    }

    return c;
}

template <typename T>
Set<T> setUnion(Set<T> &a, Set<T> &b)
{
    Set<T> c;
    typename Tree<T>::iterator it;

    SetElmt<T> *node = a.begin();

    while (node != a.end())
    {
        c.insert(node->getData());
        node = it.next(node);
    }

    node = b.begin();

    while (node != b.end())
    {
        c.insert(node->getData());
        node = it.next(node);
    }

    return c;
}

template <typename T>
bool isSubset(Set<T> &a, Set<T> &b)
{
    typename Tree<T>::iterator it;
    SetElmt<T> *node = a.begin();

    while (node != a.end())
    {
        if (!b.find(node->getData()))
        {
            return false;
        }
        node = it.next(node);
    }

    return true;
}

#endif