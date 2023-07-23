#include <iostream>
#include "set.hpp"

using namespace std;

int main()
{
    Set<int> a, b, c;

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

    c.insert(1);
    c.insert(2);
    c.insert(3);

    cout << "c = ";
    c.display();

    cout << "setInsersection(a,b) = ";
    setIntersection<int>(a, b).display();

    cout << "setUnion(a,b) = ";
    setUnion<int>(a, b).display();

    cout << "isSubset(a,b) = ";
    cout << isSubset<int>(a, b) << endl;

    cout << "isSubset(c,a) = ";
    cout << isSubset<int>(c, a) << endl;
}