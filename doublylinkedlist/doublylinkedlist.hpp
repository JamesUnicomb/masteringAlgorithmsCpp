#ifndef __DLIST_HPP__
#define __DLIST_HPP__

#include <iostream>

template <typename T>
class DLListElmt
{
private:
    T *data;
    DLListElmt *prev;
    DLListElmt *next;

public:
    DLListElmt(T data) : data(new T(data)), prev(nullptr), next(nullptr) {}
    DLListElmt<T> *&getPrev() { return next; }
    DLListElmt<T> *&getNext() { return prev; }
    T getData() { return *data; }
};

template <typename T>
class DLList
{
public:
    DLList() : size(0), head(nullptr), tail(nullptr) {}
    const int getSize() { return size; }
    DLListElmt<T> *getHead() const { return head; }
    DLListElmt<T> *getTail() const { return tail; }
    void insertTail(T data)
    {
        insertNext(tail, data);
    }
    void insertHead(T data)
    {
        insertPrev(head, data);
    }
    void removeHead()
    {
        remove(head);
    }
    void removeTail()
    {
        remove(tail);
    }
    void display()
    {
        std::cout << "nullptr=";
        DLListElmt<T> *node = head;
        while (node)
        {
            std::cout << node->getData() << "=";
            node = node->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }

private:
    void insertNext(DLListElmt<T> *node, T data)
    {

        if (size == 0)
        {
            head = tail = new DLListElmt<T>(data);
        }
        else
        {
            if (node)
            {
                DLListElmt<T> *newnode = new DLListElmt<T>(data);
                newnode->getNext() = node->getNext();
                newnode->getPrev() = node;

                if (node->getNext())
                {
                    node->getNext()->getPrev() = newnode;
                }
                else
                {
                    tail = newnode;
                }
                node->getNext() = newnode;
            }
            size += 1;
        }
    }
    void insertPrev(DLListElmt<T> *node, T data)
    {
        if (node)
        {
            if (size == 0)
            {
                head = tail = new DLListElmt<T>(data);
            }
            else
            {
                DLListElmt<T> *newnode = new DLListElmt<T>(data);
                newnode->getPrev() = node->getPrev();
                newnode->getNext() = node;

                if (node->getPrev())
                {
                    node->getPrev()->getNext() = newnode;
                }
                else
                {
                    head = newnode;
                }
                node->getPrev() = newnode;
            }
            size += 1;
        }
    }
    void remove(DLListElmt<T> *node)
    {
        if (size != 0 && node)
        {
            if (node == head)
            {
                head = node->getNext();

                if (head)
                {
                    node->getNext()->getPrev() = nullptr;
                }
                else
                {
                    tail = nullptr;
                }
            }
            else
            {
                node->getPrev()->getNext() = node->getNext();

                if (node->getNext())
                {
                    node->getNext()->getPrev() = node->getPrev();
                }
                else
                {
                    tail = node->getPrev();
                }
            }
            delete node;
            size -= 1;
        }
    }

    int size;
    DLListElmt<T> *head;
    DLListElmt<T> *tail;
};

#endif