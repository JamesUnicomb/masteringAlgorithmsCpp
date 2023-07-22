#include <iostream>
#include "../../linkedlist/linkedlist.hpp"

#define max(a, b) ((a > b) ? a : b)

template <typename T>
class TreeNode
{
public:
    TreeNode(T data) : height(1), data(new T(data)), left(nullptr), right(nullptr) {}
    TreeNode<T> *&getLeft() { return left; }
    TreeNode<T> *&getRight() { return right; }
    T getData() { return *data; }
    int getHeight() { return height; }
    void setHeight(int h) { height = h; }

private:
    int height;
    T *data;
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
class TreeToList
{
public:
    TreeToList(int size) : i(0), llist(new LList<T>()) {}
    void operator()(TreeNode<T> *node)
    {
        llist->insertTail(node->getData());
    }
    LList<T> *getLList() { return llist; }

private:
    int i;
    LList<T> *llist;
};

template <typename T>
class Tree
{
public:
    Tree() : size(0), root(nullptr) {}
    TreeNode<T> *&getRoot() { return root; }
    int getSize() { return size; }
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

    template <typename F>
    void traverseInOrder(F f)
    {
        traverseInOrder(root, f);
    }

    template <typename F>
    void traversePreOrder(F f)
    {
        traversePreOrder(root, f);
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

    LList<T> *toList()
    {
        TreeToList<T> ttl(getSize());
        traverseInOrder(ttl);
        return ttl.getLList();
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
                node->getLeft() = new TreeNode<T>(data);
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
                node->getRight() = new TreeNode<T>(data);
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
    TreeNode<T> *rotate_left(TreeNode<T> *node)
    {
        TreeNode<T> *right = node->getRight();
        node->getRight() = right->getLeft();
        right->getLeft() = node;

        node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
        right->setHeight(max(height(right->getLeft()), height(right->getRight())) + 1);

        return right;
    }
    TreeNode<T> *rotate_right(TreeNode<T> *node)
    {
        TreeNode<T> *left = node->getLeft();
        node->getLeft() = left->getRight();
        left->getRight() = node;

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

    int size;
    TreeNode<T> *root;
};