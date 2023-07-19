#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>

template <typename T>
class LListElmt
{
private:
    T *data = nullptr;
    LListElmt *next = nullptr;

public:
    LListElmt(T data) : data(new T(data)) {}
    LListElmt<T> *&getNext() { return next; }
    T getData() { return *data; }
};

template <typename T>
class LList
{
public:
    const int getSize() { return size; }
    LListElmt<T> *&getHead() { return head; }
    LListElmt<T> *&getTail() { return tail; }
    void insertTail(T data)
    {
        insertNext(tail, data);
    }
    void insertHead(T data)
    {
        insertNext(nullptr, data);
    }
    void removeHead()
    {
        removeNext(nullptr);
    }
    void display()
    {
        LListElmt<T> *node = head;
        while (node)
        {
            std::cout << node->getData() << "-";
            node = node->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }
    void reverse()
    {
        LListElmt<T> *node = head, *prev = nullptr, *next;

        while (node)
        {
            next = node->getNext();
            node->getNext() = prev;
            prev = node;
            node = next;
        }
        tail = head;
        head = prev;
    }

private:
    void insertNext(LListElmt<T> *node, T data)
    {
        if (size == 0)
        {
            head = tail = new LListElmt<T>(data);
        }
        else if (!node)
        {
            LListElmt<T> *node = new LListElmt<T>(data);
            node->getNext() = head;
            head = node;
        }
        else if (node->getNext())
        {
            LListElmt<T> *next = node->getNext();
            next->getNext() = new LListElmt<T>(data);
            node->getNext()->getNext() = next;
        }
        else
        {
            node->getNext() = new LListElmt<T>(data);
            tail = node->getNext();
        }
        size += 1;
    }
    void removeNext(LListElmt<T> *node)
    {

        if (!node)
        {
            LListElmt<T> *next = head->getNext();
            delete head;
            head = next;
        }
        else
        {
            if (size != 0)
            {
                LListElmt<T> *next = node->getNext();
                node->getNext() = next->getNext();
                delete next;
            }
        }
        size -= 1;
    }

    int size = 0;
    LListElmt<T> *head = nullptr;
    LListElmt<T> *tail = nullptr;
};

#endif