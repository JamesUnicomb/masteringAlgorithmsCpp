#ifndef __BINARYTREE_HPP__
#define __BINARYTREE_HPP__

#include <iostream>
#include "../../linkedlist/linkedlist.hpp"

template <typename T>
class TreeNode
{
public:
    TreeNode(T data) : height(1), data(new T(data)), parent(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(T data, TreeNode<T> *parent) : height(1), data(new T(data)), parent(parent), left(nullptr), right(nullptr) {}
    TreeNode<T> *&getParent() { return parent; }
    inline TreeNode<T> *&getLeft() { return left; }
    inline TreeNode<T> *&getRight() { return right; }
    inline T &getData() { return *data; }
    inline int getHeight() { return height; }
    inline void setHeight(int height) { this->height = height; }
    ~TreeNode()
    {
#if DEBUG
        std::cout << "~TreeNode<T>(" << *data << ")" << std::endl;
#endif
        delete data;
    }

private:
    int height;
    T *data;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

// functors for performing actions while traversing
template <typename T>
class PrintTreeNode
{
public:
    void operator()(TreeNode<T> *node)
    {
        std::cout << node->getData() << " ";
    }
};

template <typename T>
class DeleteTreeNode
{
public:
    void operator()(TreeNode<T> *node)
    {
        delete node;
    }
};

template <typename T>
class Tree
{
public:
    Tree() : size(0), root(nullptr) {}
    Tree(Tree<T> &rhs) : size(0), root(nullptr)
    {
        Tree<T>::iterator it;

        for (it = rhs.begin(); it != rhs.end(); it++)
        {
            this->insert(it->getData());
        }
    }
    inline TreeNode<T> *&getRoot() { return root; }
    inline int getSize() { return size; }
    inline int max(int a, int b)
    {
        return ((a > b) ? a : b);
    }

    class iterator
    {
    public:
        iterator() : ptr(nullptr) {}
        iterator(TreeNode<T> *node) : ptr(node) {}
        static TreeNode<T> *first(TreeNode<T> *node)
        {
            if (node)
            {
                while (node->getLeft())
                {
                    node = node->getLeft();
                }
                return node;
            }
            return nullptr;
        }
        TreeNode<T> &operator*()
        {
            return *ptr;
        }
        iterator *operator=(TreeNode<T> *rhs)
        {
            ptr = rhs;
            return this;
        }
        bool operator!=(TreeNode<T> *rhs)
        {
            return ptr != rhs;
        }
        iterator operator++()
        {
            next();
            return *this;
        }
        iterator operator++(int)
        {
            next();
            return *this;
        }
        TreeNode<T> *operator->() { return ptr; }

    private:
        void next()
        {
            ptr = next(ptr);
        }
        TreeNode<T> *next(TreeNode<T> *node)
        {
            if (node->getRight())
            {
                return first(node->getRight());
            }

            while (node->getParent() && node->getParent()->getRight() == node)
            {
                node = node->getParent();
            }

            if (node->getParent() && node->getParent()->getRight() != node)
            {
                return node->getParent();
            }

            return nullptr;
        }
        TreeNode<T> *ptr;
    };

    TreeNode<T> *begin()
    {
        return iterator::first(root);
    }

    TreeNode<T> *end()
    {
        return nullptr;
    }

    class preorder_iterator
    {
    public:
        preorder_iterator() : ptr(nullptr) {}
        preorder_iterator(TreeNode<T> *node) : ptr(node) {}
        TreeNode<T> &operator*()
        {
            return *ptr;
        }
        preorder_iterator *operator=(TreeNode<T> *rhs)
        {
            ptr = rhs;
            return this;
        }
        bool operator!=(TreeNode<T> *rhs)
        {
            return ptr != rhs;
        }
        preorder_iterator operator++()
        {
            next();
            return *this;
        }
        preorder_iterator operator++(int)
        {
            next();
            return *this;
        }
        TreeNode<T> *operator->() { return ptr; }

    private:
        void next()
        {
            ptr = next(ptr);
        }
        TreeNode<T> *next(TreeNode<T> *node)
        {
            if (!node->getLeft())
            {
                node = node->getRight();
            }
            else
            {
                TreeNode<T> *curr = node->getLeft();
                while (curr->getRight() && curr->getRight() != node)
                {
                    curr = curr->getRight();
                }

                if (curr->getRight() == node)
                {
                    curr->getRight() = nullptr;
                    node = node->getRight();
                }
                else
                {
                    curr->getRight() = node;
                    node = node->getLeft();
                }
            }

            return node;
        }
        TreeNode<T> *ptr;
    };

    TreeNode<T> *preorder_begin()
    {
        return root;
    }

    TreeNode<T> *preorder_end()
    {
        return nullptr;
    }

    void insert(T data)
    {
        if (root)
        {
            root = insert(root, data);
        }
        else
        {
            root = new TreeNode<T>(data);
            size += 1;
        }
    }
    TreeNode<T> *find(T data)
    {
        return find(root, data);
    }
    void remove(T data)
    {
        remove(root, data);
    }
    template <typename F>
    void traverseInOrder(F f)
    {
        if (root)
        {
            traverseInOrder(root, f);
        }
    }

    template <typename F>
    void traversePreOrder(F f)
    {
        if (root)
        {
            traversePreOrder(root, f);
        }
    }

    template <typename F>
    void traversePostOrder(F f)
    {
        if (root)
        {
            traversePostOrder(root, f);
        }
    }

    template <typename F>
    void traverseLevelOrder(F f)
    {
        for (int i = 0; i < root->getHeight(); i++)
        {
            traverseLevelOrder(root, f, i);
        }
    }

    void display()
    {
        PrintTreeNode<T> pn;
        std::cout << "DisplayBegin:" << std::endl;
        traverseInOrder(pn);
        std::cout << std::endl;
        std::cout << ":DisplayEnd" << std::endl;
    }

    void pprint()
    {
        pprint(root, 0);
    }

    void pprint(TreeNode<T> *node, int d)
    {
        if (d == 0)
        {
            printf("B:");
        }
        if (node)
        {
            d += 1;

            printf("%d,%d,%d\n", node->getData(), height(node), balance(node));

            if (node->getLeft())
            {
                for (int i = 0; i < d; i++)
                    printf(" ");
                printf("L:");
                pprint(node->getLeft(), d);
            }

            if (node->getRight())
            {
                for (int i = 0; i < d; i++)
                    printf(" ");
                printf("R:");
                pprint(node->getRight(), d);
            }
        }
    }

    ~Tree()
    {
        DeleteTreeNode<T> dn;
        traversePostOrder(dn);
    }

private:
    inline int height(TreeNode<T> *node)
    {
        return (node) ? node->getHeight() : 0;
    }
    inline int balance(TreeNode<T> *node)
    {
        return (node) ? height(node->getRight()) - height(node->getLeft()) : 0;
    }
    TreeNode<T> *insert(TreeNode<T> *node, T data)
    {
        if (data < node->getData())
        {
            if (node->getLeft())
            {
                node->getLeft() = insert(node->getLeft(), data);
            }
            else
            {
                node->getLeft() = new TreeNode<T>(data, node);
                size += 1;
            }
        }
        else if (data > node->getData())
        {
            if (node->getRight())
            {
                node->getRight() = insert(node->getRight(), data);
            }
            else
            {
                node->getRight() = new TreeNode<T>(data, node);
                size += 1;
            }
        }

        node = rebalance(node);

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

        return node;
    }
    template <typename F>
    void traverseInOrder(TreeNode<T> *node, F &f)
    {
        if (node->getLeft())
        {
            traverseInOrder(node->getLeft(), f);
        }
        f(node);
        if (node->getRight())
        {
            traverseInOrder(node->getRight(), f);
        }
    }
    template <typename F>
    void traversePreOrder(TreeNode<T> *node, F &f)
    {
        f(node);
        if (node->getLeft())
        {
            traverseInOrder(node->getLeft(), f);
        }
        if (node->getRight())
        {
            traverseInOrder(node->getRight(), f);
        }
    }
    template <typename F>
    void traversePostOrder(TreeNode<T> *node, F &f)
    {
        if (node->getLeft())
        {
            traverseInOrder(node->getLeft(), f);
        }
        if (node->getRight())
        {
            traverseInOrder(node->getRight(), f);
        }
        f(node);
    }

    template <typename F>
    void traverseLevelOrder(TreeNode<T> *node, F f, int level)
    {
        if (node)
        {
            if (level == 0)
            {
                f(node);
            }
            else
            {
                traverseLevelOrder(node->getLeft(), f, level - 1);
                traverseLevelOrder(node->getRight(), f, level - 1);
            }
        }
    }

    TreeNode<T> *rotate_left(TreeNode<T> *node)
    {
        TreeNode<T> *right = node->getRight();
        node->getRight() = right->getLeft();
        right->getLeft() = node;

        right->getParent() = node->getParent();
        if (node->getRight())
        {
            node->getRight()->getParent() = node;
        }
        node->getParent() = right;

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
        right->setHeight(max(height(right->getLeft()), height(right->getRight())) + 1);

        return right;
    }
    TreeNode<T> *rotate_right(TreeNode<T> *node)
    {
        TreeNode<T> *left = node->getLeft();
        node->getLeft() = left->getRight();
        left->getRight() = node;

        left->getParent() = node->getParent();
        if (node->getLeft())
        {
            node->getLeft()->getParent() = node;
        }
        node->getParent() = left;

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
        left->setHeight(max(height(left->getLeft()), height(left->getRight())) + 1);

        return left;
    }

    TreeNode<T> *rotate_right_left(TreeNode<T> *node)
    {
        node->getRight() = rotate_right(node->getRight());
        node = rotate_left(node);

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

        return node;
    }

    TreeNode<T> *rotate_left_right(TreeNode<T> *node)
    {
        node->getLeft() = rotate_left(node->getLeft());
        node = rotate_right(node);

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);

        return node;
    }

    TreeNode<T> *rebalance(TreeNode<T> *node)
    {
        int b = 0, lb = 0, rb = 0;

        b = balance(node);
        lb = balance(node->getLeft());
        rb = balance(node->getRight());

        if (b < -1 && lb == -1)
        {
            return rotate_right(node);
        }
        else if (b > 1 && rb == 1)
        {
            return rotate_left(node);
        }
        else if (b < -1 && lb == 1)
        {
            return rotate_left_right(node);
        }
        else if (b > 1 && rb == -1)
        {
            return rotate_right_left(node);
        }

        return node;
    }

    TreeNode<T> *find(TreeNode<T> *node, T data)
    {
        if (node)
        {
            if (data == node->getData())
            {
                return node;
            }
            else if (data < node->getData())
            {
                return find(node->getLeft(), data);
            }
            else if (data > node->getData())
            {
                return find(node->getRight(), data);
            }
        }
        return nullptr;
    }

    TreeNode<T> *remove(TreeNode<T> *node, T data)
    {
        if (node)
        {
            if (data < node->getData())
            {
                node->getLeft() = remove(node->getLeft(), data);
                node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
                return node;
            }
            else if (data > node->getData())
            {
                node->getRight() = remove(node->getRight(), data);
                node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
                return node;
            }

            size -= 1;
            if (node->getLeft() && node->getRight())
            {
                TreeNode<T> *parent = node;
                TreeNode<T> *succ = node->getRight();

                while (succ->getLeft())
                {
                    parent = succ;
                    succ = succ->getLeft();
                }

                if (parent != node)
                {
                    parent->getLeft() = succ->getRight();
                }
                else
                {
                    parent->getRight() = succ->getRight();
                }

                node->getData() = succ->getData();

                delete succ;
                return node;
            }
            else if (node->getLeft())
            {
                TreeNode<T> *tmp = node->getLeft();
                tmp->getParent() = node->getParent();
                delete node;
                return tmp;
            }
            else if (node->getRight())
            {
                TreeNode<T> *tmp = node->getRight();
                tmp->getParent() = node->getParent();
                delete node;
                return tmp;
            }
            else
            {
                delete node;
                return nullptr;
            }
        }

        return node;
    }

    int size;
    TreeNode<T> *root;
};

#endif