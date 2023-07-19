#include <iostream>
#include "deque.hpp"

using namespace std;

int main()
{
    Deque<int> deque;
    cout << "deque example" << endl;

    deque.insertTail(1);
    deque.insertHead(2);
    // deque.insertTail(2);
    //  deque.push_front(3);
    //  deque.push_back(4);
    //  deque.push_back(5);
    //  deque.push_back(6);

    deque.display();
    // cout << "size = " << deque.getSize() << endl;
    cout << "peek_back = " << deque.peek_back()->getData() << endl;
    cout << "peek_front = " << deque.peek_front()->getData() << endl;
}