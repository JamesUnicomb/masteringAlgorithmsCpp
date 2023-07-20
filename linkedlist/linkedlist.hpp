#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>

template <typename T>
class LListElmt
{
private:
    T *data;
    LListElmt *next;

public:
    LListElmt() : data(nullptr), next(nullptr) {}
    LListElmt(T data) : data(new T(data)), next(nullptr) {}
    LListElmt<T> *&getNext() { return next; }
    T getData() { return *data; }
};

template <typename T>
class LList
{
public:
    int size;
    LList() : size(0), head(nullptr), tail(nullptr) {}
    const int getSize() { return size; }
    LListElmt<T> *getHead() const { return head; }
    LListElmt<T> *getTail() const { return tail; }
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
        LListElmt<T> *newnode = new LListElmt<T>(data);
        if (node)
        {
            if (node->getNext())
            {
                newnode->getNext() = node->getNext();
            }
            else
            {
                tail = newnode;
            }
            node->getNext() = newnode;
        }
        else
        {
            if (size == 0)
            {
                tail = newnode;
            }
            newnode->getNext() = head;
            head = newnode;
        }
        size += 1;
    }
    void removeNext(LListElmt<T> *node)
    {
        if (size != 0)
        {
            if (node)
            {

                LListElmt<T> *next = node->getNext();
                node->getNext() = next->getNext();
                delete next;

                if (!node->getNext())
                {
                    tail = node;
                }
            }
            else
            {
                LListElmt<T> *next = head->getNext();
                delete head;
                head = next;

                if (size == 1)
                {
                    tail = nullptr;
                }
            }
        }
        size -= 1;
    }
    LListElmt<T> *head;
    LListElmt<T> *tail;
};

#endif