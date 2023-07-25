#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <math.h>
#include <iostream>

template <typename T>
class PrintNode
{
public:
    void operator()(T data)
    {
        std::cout << data << " ";
    }
};

template <typename T>
class LessThan
{
public:
    bool operator()(T *a, T *b)
    {
        return *a < *b ? true : false;
    }
};

template <typename T>
class GreaterThan
{
public:
    bool operator()(T *a, T *b)
    {
        return *a > *b ? true : false;
    }
};

template <typename T, typename C>
class Heap
{
public:
    Heap() : size(0), n(0), tree(nullptr) {}
    void insert(T data)
    {
        if (tree)
        {
            if (size + 1 > n)
            {
                resize();
            }
            tree[size] = new T(data);
        }
        else
        {
            n += 1;
            tree = new T *[n];
            tree[size] = new T(data);
        }
        size += 1;
        heapify();
    }
    T extract()
    {
        T *data = tree[0];
        T *save = tree[size - 1];

        int i = 0, m, l, r;
        tree[0] = save;
        size -= 1;

        while (true)
        {
            l = getLeft(i);
            r = getRight(i);

            if (l < size && compare(tree[l], tree[i]))
            {
                m = l;
            }
            else
            {
                m = i;
            }

            if (r < size && compare(tree[r], tree[m]))
            {
                m = r;
            }

            if (m == i)
            {
                break;
            }
            else
            {
                swap(tree[m], tree[i]);
                i = m;
            }
        }

        T out = *data;
        tree[size] = nullptr;

        delete data;

        return out;
    }
    int getSize() const
    {
        return size;
    }
    void display()
    {
        PrintNode<T> pn;
        traverseLevelOrder(pn);
        std::cout << std::endl;
    }
    ~Heap()
    {
        if (tree)
        {
            for (int i = 0; i < size; i++)
            {
                delete tree[i];
            }
            delete[] tree;
        }
    }

private:
    void swap(T *a, T *b)
    {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }
    inline int getParent(int i)
    {
        return floor((i - 1) / 2);
    }
    inline int getLeft(int i)
    {
        return 2 * i + 1;
    }
    inline int getRight(int i)
    {
        return 2 * i + 2;
    }
    void heapify()
    {
        int i = size - 1;
        T *a = tree[i], *b = tree[getParent(i)];
        while (compare(a, b) && i != 0)
        {
            swap(a, b);
            i = getParent(i);
            a = tree[i];
            b = tree[getParent(i)];
        }
    }
    void resize()
    {
        int newn = 2 * n;

        T **newtree = new T *[newn]();

        for (int i = 0; i < n; i++)
        {
            newtree[i] = tree[i];
        }

        if (tree)
            delete[] (tree);

        tree = newtree;
        n = newn;
    }

    template <typename F>
    void traverseLevelOrder(F f)
    {
        for (int i = 0; i < size; i++)
        {
            f(*tree[i]);
        }
    }

    C compare;
    T **tree;
    int size;
    int n;
};

#endif