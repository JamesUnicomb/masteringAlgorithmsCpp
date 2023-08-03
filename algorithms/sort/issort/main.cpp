#include <iostream>

#include "issort.hpp"

using namespace std;

int main()
{
    int arr[10] = {5, 2, 1, 4, 8, 7, 3, 9, 0, 6};

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    CompareT<int> c;
    issort<int>(arr, 10, c);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}