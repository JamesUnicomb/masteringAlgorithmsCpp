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
    K getKey()
    {
        return key;
    }
    T getData()
    {
        return data;
    }

private:
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
    TreeNode<KeyValueElmt<K, T>> *begin()
    {
        return tree.begin();
    }
    TreeNode<KeyValueElmt<K, T>> *end()
    {
        return tree.end();
    }

    using iterator = typename Tree<KeyValueElmt<K, T>>::iterator;

private:
    Tree<KeyValueElmt<K, T>> tree;
};

#endif