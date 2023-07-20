#include <iostream>
#include "doublylinkedlist.hpp"

using namespace std;

int main()
{
    DLList<int> list;
    cout << "doubly linked list example" << endl;
    list.insertTail(1);
    list.insertHead(2);
    list.insertTail(3);
    list.insertHead(4);
    list.insertTail(5);

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.removeHead();

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.insertHead(6);

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.removeTail();

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.insertTail(0);

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.removeHead();
    list.removeHead();
    list.removeHead();
    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.removeHead();
    list.removeHead();
    list.display();
    cout << "size = " << list.getSize() << endl;
    if (!list.getHead())
    {
        cout << "head = nullptr" << endl;
    }
    if (!list.getTail())
    {
        cout << "tail = nullptr" << endl;
    }
}