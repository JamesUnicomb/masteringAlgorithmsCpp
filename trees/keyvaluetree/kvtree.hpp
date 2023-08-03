#ifndef __KVTREE_HPP__
#define __KVTREE_HPP__

#include "../binarytree/binarytree.hpp"

template <typename K, typename T>
class KeyValueElmt
{
public:
    KeyValueElmt(K key) : key(key) {}
    KeyValueElmt(K key, T data) : key(key), data(data) {}
    bool operator<(KeyValueElmt<K, T> rhs)
    {
        return this->key < rhs.key;
    }
    bool operator>(KeyValueElmt<K, T> rhs)
    {
        return this->key > rhs.key;
    }
    bool operator==(KeyValueElmt<K, T> rhs)
    {
        return this->key == rhs.key;
    }

    K key;
    T data;
};

template <typename K, typename T>
class KeyValueTree
{
public:
    void insert(K key, T data)
    {
        tree.insert(KeyValueElmt<K, T>(key, data));
    }
    KeyValueElmt<K, T> *find(K key)
    {
        return &tree.find(KeyValueElmt<K, T>(key))->getData();
    }

private:
    Tree<KeyValueElmt<K, T>> tree;
};

#endif