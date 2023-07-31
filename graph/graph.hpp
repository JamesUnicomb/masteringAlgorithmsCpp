#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
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

template <typename T, typename Pred>
void depth_first_search(const Graph<T> &graph, AdjacencyList<T> *vertex, Pred &pred)
{
    Set<AdjacencyList<T> *> visited;
    Stack<AdjacencyList<T> *> next;
    typename Set<AdjacencyList<T> *>::iterator it;

    next.push(vertex);

    while (next.getSize())
    {
        vertex = next.pop()->getData();

        pred(vertex);
        visited.insert(vertex);

        for (it = vertex->getAdjacency().begin(); it != vertex->getAdjacency().end(); it++)
        {
            if (!visited.find(it->getData()))
            {
                next.push(it->getData());
            }
        }
    }
}

template <typename T, typename Pred>
void breadth_first_search(const Graph<T> &graph, AdjacencyList<T> *vertex, Pred &pred)
{
    Set<AdjacencyList<T> *> visited;
    Queue<AdjacencyList<T> *> next;
    typename Set<AdjacencyList<T> *>::iterator it;

    next.enqueue(vertex);

    while (next.getSize())
    {
        vertex = next.dequeue()->getData();

        pred(vertex);
        visited.insert(vertex);

        for (it = vertex->getAdjacency().begin(); it != vertex->getAdjacency().end(); it++)
        {
            if (!visited.find(it->getData()))
            {
                next.enqueue(it->getData());
            }
        }
    }
}

#endif