#include <iostream>

#include "kvtree.hpp"

using namespace std;

int main()
{
    KeyValueTree<string, int> kvtree;
    kvtree.insert("james", 1);
    kvtree.insert("alex", 2);
    kvtree.insert("michael", 3);
    cout << "hello tree" << endl;

    KeyValueElmt<string, int> *kv = kvtree.find("michael");

    cout << kv->key << " = " << kv->data << endl;
}