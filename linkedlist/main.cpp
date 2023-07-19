#include <iostream>
#include "linkedlist.hpp"

using namespace std;

int main()
{
    LList<int> list;
    cout << "linked list example" << endl;
    list.insertTail(1);
    list.insertTail(2);
    list.insertTail(3);
    list.insertTail(4);
    list.insertTail(5);

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;

    list.reverse();

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

    list.insertTail(0);

    list.display();
    cout << "size = " << list.getSize() << endl;
    cout << "head = " << list.getHead()->getData() << endl;
    cout << "tail = " << list.getTail()->getData() << endl;
}