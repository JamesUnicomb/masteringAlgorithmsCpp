#include <iostream>
#include "queue.hpp"

using namespace std;

int main()
{
    Queue<int> queue;
    cout << "queue example" << endl;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "size = " << queue.getSize() << endl;
    cout << "peek = " << queue.peek()->getData() << endl;
    cout << "dequeue = " << queue.dequeue()->getData() << endl;
    cout << "peek = " << queue.peek()->getData() << endl;
    cout << "dequeue = " << queue.dequeue()->getData() << endl;
    cout << "dequeue = " << queue.dequeue()->getData() << endl;

    if (!queue.peek())
    {
        cout << "queue empty" << endl;
    }
}