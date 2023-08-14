#include <iostream>

#include "kvtree.hpp"

using namespace std;

int main()
{
    KeyValueTree<string, int> kvtree;
    kvtree.insert("james", 1);
    kvtree.insert("alex", 2);
    kvtree.insert("michael", 3);
    cout << "key value tree example:" << endl;

    auto *kv = kvtree.find("michael");

    cout << kv->getKey() << " = " << kv->getData() << endl;
}