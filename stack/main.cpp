#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
    Stack<int> stack;
    cout << "stack example" << endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "size = " << stack.getSize() << endl;
    cout << "pop = " << stack.pop()->getData() << endl;
    cout << "peek = " << stack.peek()->getData() << endl;
    cout << "pop = " << stack.pop()->getData() << endl;
    cout << "pop = " << stack.pop()->getData() << endl;
}