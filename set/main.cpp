#include <iostream>
#include "set.hpp"

using namespace std;

int main()
{
    Set<int> a, b;

    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);

    cout << "a = ";
    a.display();

    b.insert(4);
    b.insert(5);
    b.insert(6);

    cout << "b = ";
    b.display();

    cout << "insersection(a,b) = ";
    intersection<int>(a, b).display();
}