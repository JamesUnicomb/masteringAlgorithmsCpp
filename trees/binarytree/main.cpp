#include <iostream>
#include "binarytree.hpp"

using namespace std;

int main()
{
    Tree<int> tree;

    for (int i = 0; i < 7; i++)
    {
        tree.insert(i);
    }

    tree.display();
    tree.pprint();

    cout << "height = " << tree.getRoot()->getHeight() << endl;

    cout << "size = " << tree.getSize() << endl;

    LList<int> llist = *tree.toList();

    llist.display();

    int s1 = 5;
    if (tree.find(s1))
    {
        cout << "found:" << s1 << endl;
    }
    else
    {
        cout << "did not find:" << s1 << endl;
    }

    int s2 = 15;
    if (tree.find(s2))
    {
        cout << "found:" << s2 << endl;
    }
    else
    {
        cout << "did not find:" << s2 << endl;
    }
}