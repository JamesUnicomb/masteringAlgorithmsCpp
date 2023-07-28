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

    using iterator = typename Tree<T>::iterator;

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
        std::cout << "{";

        iterator it = tree.begin();
        while (it != tree.end())
        {
            std::cout << it->getData();
            it++;
            if (it != nullptr)
            {
                std::cout << ",";
            }
        }
        std::cout << "}" << std::endl;
    }

private:
    Tree<T> tree;
};

template <typename T>
Set<T> setIntersection(Set<T> &a, Set<T> &b)
{
    Set<T> c;
    typename Set<T>::iterator it;

    int n = a.getSize(), m = b.getSize();

    if (n < m)
    {
        for (it = a.begin(); it != a.end(); it++)
        {
            if (b.find(it->getData()))
            {
                c.insert(it->getData());
            }
        }
    }
    else
    {
        for (it = b.begin(); it != b.end(); it++)
        {
            if (a.find(it->getData()))
            {
                c.insert(it->getData());
            }
        }
    }

    return c;
}

template <typename T>
Set<T> setUnion(Set<T> &a, Set<T> &b)
{
    Set<T> c;
    typename Set<T>::iterator it;

    for (it = a.begin(); it != a.end(); it++)
    {
        c.insert(it->getData());
    }

    for (it = b.begin(); it != b.end(); it++)
    {
        c.insert(it->getData());
    }

    return c;
}

template <typename T>
bool isSubset(Set<T> &a, Set<T> &b)
{
    typename Set<T>::iterator it;

    for (it = a.begin(); it != a.end(); it++)
    {
        if (!b.find(it->getData()))
        {
            return false;
        }
    }

    return true;
}

#endif