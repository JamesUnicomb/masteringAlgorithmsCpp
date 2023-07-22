#include <iostream>
#include "binarytree.hpp"

using namespace std;

int main()
{
    Tree<int> tree;

    tree.insert(80);
    tree.insert(9);
    tree.insert(75);
    tree.insert(25);
    tree.insert(24);
    tree.insert(12);
    tree.insert(57);
    tree.insert(53);
    tree.insert(88);
    tree.insert(6);
    tree.insert(23);
    tree.insert(64);
    tree.insert(38);
    tree.insert(81);
    tree.insert(17);
    tree.insert(14);
    tree.insert(4);
    tree.insert(87);
    tree.insert(84);
    tree.insert(31);
    tree.insert(29);

    tree.display();
    tree.pprint();

    cout << "height = " << tree.getRoot()->getHeight() << endl;

    cout << "size = " << tree.getSize() << endl;

    LList<int> llist = *tree.toList();

    llist.display();
}