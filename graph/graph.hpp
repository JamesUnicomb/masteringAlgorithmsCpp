#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../set/set.hpp"

template <typename T>
class AdjacencyList
{
public:
    AdjacencyList(T data) : vertex(new T(data)), adjlist() {}
    T getVertex() { return *vertex; }
    void addAdjacency(AdjacencyList<T> *adj)
    {
        adjlist.insert(adj);
    }
    Set<AdjacencyList<T> *> &getAdjacency() { return adjlist; }
    ~AdjacencyList()
    {
        std::cout << "adjacency delete: " << *vertex << std::endl;
    }

private:
    T *vertex;
    Set<AdjacencyList<T> *> adjlist;
};

template <typename T>
class Graph
{
public:
    Graph() : vcnt(0), ecnt(0) {}
    int getVertexCount() const { return vcnt; }
    int getEdgeCount() const { return ecnt; }
    void addVertex(T data)
    {
        adjlists.insert(new AdjacencyList<T>(data));
        vcnt += 1;
    }
    void addEdge(AdjacencyList<T> *fromNode, AdjacencyList<T> *toNode)
    {
        fromNode->addAdjacency(toNode);
        ecnt += 1;
    }
    AdjacencyList<T> *find(T data)
    {
        AdjacencyList<T> *node;
        typename Set<AdjacencyList<T> *>::iterator it;

        it = adjlists.begin();

        while (it != adjlists.end())
        {
            if (it->getData()->getVertex() == data)
            {
                node = it->getData();
                break;
            }
            it++;
        }

        return node;
    }

    void display()
    {
        typename Set<AdjacencyList<T> *>::iterator nodeIt, edgeIt;

        for (nodeIt = adjlists.begin(); nodeIt != adjlists.end(); nodeIt++)
        {
            AdjacencyList<T> *vertex = nodeIt->getData();

            for (edgeIt = vertex->getAdjacency().begin(); edgeIt != vertex->getAdjacency().end(); edgeIt++)
            {
                std::cout << vertex->getVertex() << "," << edgeIt->getData()->getVertex() << std::endl;
            }
        }
    }

    ~Graph() {}
    Set<AdjacencyList<T> *> adjlists;

private:
    int vcnt;
    int ecnt;
};

template <typename T>
void get_paths(AdjacencyList<T> *fromNode, AdjacencyList<T> *toNode, Set<T> &s, LList<T> l)
{
    s.insert(fromNode->getVertex());

    l.insertTail(fromNode->getVertex());

    if (fromNode == toNode)
    {
        l.display();
        return;
    }

    AdjacencyList<T> *node = fromNode;
    typename Set<AdjacencyList<T> *>::iterator it;

    for (it = node->getAdjacency().begin(); it != node->getAdjacency().end(); it++)
    {
        if (!s.find(it->getData()->getVertex()))
        {
            get_paths(it->getData(), toNode, s, l);
        }
    }
}

template <typename T>
void get_paths(AdjacencyList<T> *fromNode, AdjacencyList<T> *toNode)
{
    if (fromNode && toNode)
    {
        LList<int> l;
        Set<int> s;
        get_paths(fromNode, toNode, s, l);
    }
}

#endif