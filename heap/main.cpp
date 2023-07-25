#include <iostream>
#include "heap.hpp"

using namespace std;

int main()
{
    Heap<int, GreaterThan<int>> heap;

    for (int i = 0; i < 10; i++)
    {
        heap.insert(i);
        heap.display();
    }

    cout << "size = " << heap.getSize() << endl;
    heap.display();

    int d = heap.extract();
    heap.display();

    cout << "extracted : " << d << endl;
    cout << "size = " << heap.getSize() << endl;
}