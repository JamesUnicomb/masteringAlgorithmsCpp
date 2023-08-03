#include <iostream>

#include "qksort.hpp"

using namespace std;

class CompareInt
{
public:
    inline bool operator()(int a, int b)
    {
        return a > b ? true : false;
    }
};

int main()
{
    int arr[10] = {5, 2, 1, 4, 8, 7, 3, 9, 0, 6};

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    CompareInt f;
    partition<int>(arr, 0, 9, f);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    qksort<int>(arr, 10, f);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}