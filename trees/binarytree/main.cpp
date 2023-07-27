#include <iostream>
#include "binarytree.hpp"

using namespace std;

int main()
{
    Tree<int> tree;

    for (int i = 0; i < 8; i++)
    {
        tree.insert(i);
    }

    cout << "level order: ";
    PrintTreeNode<int> pn;
    tree.traverseLevelOrder(pn);
    std::cout << endl;

    tree.display();
    tree.pprint();

    cout << "height = " << tree.getRoot()->getHeight() << endl;
    cout << "size = " << tree.getSize() << endl;

    tree.remove(7);
    tree.remove(3);
    tree.pprint();

    cout << "height = " << tree.getRoot()->getHeight() << endl;
    cout << "size = " << tree.getSize() << endl;

    LList<int> llist = *tree.toList();
    llist.display();

    for (int s = 0; s < 12; s++)
    {
        if (tree.find(s))
        {
            cout << "found:" << s << endl;
        }
        else
        {
            cout << "did not find:" << s << endl;
        }
    }

    cout << "iterator display start:" << endl;

    TreeNode<int> *node = tree.begin();
    Tree<int>::iterator it;

    while (node)
    {
        cout << node->getData() << " ";
        node = it.next(node);
    }
    cout << endl
         << ": iterator display finish" << endl;
}