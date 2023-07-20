#include <iostream>
#include "deque.hpp"

using namespace std;

int main()
{
    Deque<int> deque;
    cout << "deque example" << endl;

    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);
    deque.push_back(4);
    deque.push_back(5);
    deque.push_back(6);

    cout << "size = " << deque.getSize() << endl;
    cout << "peek_back = " << deque.peek_back()->getData() << endl;
    cout << "peek_front = " << deque.peek_front()->getData() << endl;
    cout << "pop_front = " << deque.pop_front()->getData() << endl;
    cout << "pop_back = " << deque.pop_back()->getData() << endl;
    cout << "pop_front = " << deque.pop_front()->getData() << endl;
    cout << "pop_back = " << deque.pop_back()->getData() << endl;
    cout << "peek_back = " << deque.peek_back()->getData() << endl;
    cout << "peek_front = " << deque.peek_front()->getData() << endl;
}