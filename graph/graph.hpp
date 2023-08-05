#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../set/set.hpp"
#include "../trees/keyvaluetree/kvtree.hpp"

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
        delete vertex;
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
    KeyValueTree<T, AdjacencyList<T> *> &getAdjacencyLists() { return adjlists; }
    void addVertex(T data)
    {
        adjlists.insert(data, new AdjacencyList<T>(data));
        vcnt += 1;
    }
    void addEdge(T from, T to)
    {
        AdjacencyList<T> *fromVertex = find(from);
        AdjacencyList<T> *toVertex = find(to);

        if (fromVertex && toVertex)
        {
            fromVertex->addAdjacency(toVertex);
            ecnt += 1;
        }
    }
    AdjacencyList<T> *find(T data)
    {

        return adjlists.find(data)->getData();
    }

    void display_edge_list()
    {
        typename KeyValueTree<T, AdjacencyList<T> *>::iterator vertexIt;
        typename Set<AdjacencyList<T> *>::iterator edgeIt;

        for (vertexIt = adjlists.begin(); vertexIt != adjlists.end(); vertexIt++)
        {
            AdjacencyList<T> *vertex = vertexIt->getData().getData();

            for (edgeIt = vertex->getAdjacency().begin(); edgeIt != vertex->getAdjacency().end(); edgeIt++)
            {
                std::cout << vertex->getVertex() << "," << edgeIt->getData()->getVertex() << std::endl;
            }
        }
    }

    void display_vertices()
    {
        typename KeyValueTree<T, AdjacencyList<T> *>::iterator vertexIt;
        typename Set<AdjacencyList<T> *>::iterator edgeIt;

        for (vertexIt = adjlists.begin(); vertexIt != adjlists.end(); vertexIt++)
        {
            AdjacencyList<T> *vertex = vertexIt->getData().getData();

            std::cout << vertex->getVertex() << std::endl;
        }
    }

    ~Graph() {}

private:
    KeyValueTree<T, AdjacencyList<T> *> adjlists;

    int vcnt;
    int ecnt;
};

template <typename T, typename Pred>
void depth_first_search(AdjacencyList<T> *vertex, Pred &pred)
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
void breadth_first_search(AdjacencyList<T> *vertex, Pred &pred)
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

template <typename T>
bool is_cyclic(AdjacencyList<T> *vertex)
{
    Set<AdjacencyList<T> *> visited;
    Queue<AdjacencyList<T> *> next;
    typename Set<AdjacencyList<T> *>::iterator it;

    next.enqueue(vertex);

    while (next.getSize())
    {
        vertex = next.dequeue()->getData();

        visited.insert(vertex);

        for (it = vertex->getAdjacency().begin(); it != vertex->getAdjacency().end(); it++)
        {
            next.enqueue(it->getData());
            if (visited.find(it->getData()))
            {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool is_cyclic(Graph<T> graph)
{
    AdjacencyList<T> *vertex;
    typename KeyValueTree<T, AdjacencyList<T> *>::iterator it;

    for (it = graph.getAdjacencyLists().begin(); it != graph.getAdjacencyLists().end(); it++)
    {
        vertex = it->getData().getData();
        if (is_cyclic(vertex))
        {
            return true;
        }
    }

    return false;
}

template <typename T>
LList<T> find_shortest_path(AdjacencyList<T> *fromVertex, AdjacencyList<T> *toVertex)
{
    AdjacencyList<T> *vertex = fromVertex;
    typename Set<AdjacencyList<T> *>::iterator it;
    Set<AdjacencyList<T> *> visited;
    Queue<AdjacencyList<T> *> next;
    Graph<T> paths;

    next.enqueue(vertex);

    while (next.getSize())
    {
        vertex = next.dequeue()->getData();

        paths.addVertex(vertex->getVertex());

        for (it = vertex->getAdjacency().begin(); it != vertex->getAdjacency().end(); it++)
        {
            if (!visited.find(it->getData()))
            {
                paths.addVertex(it->getData()->getVertex());

                paths.addEdge(it->getData()->getVertex(), vertex->getVertex());
                paths.addEdge(vertex->getVertex(), it->getData()->getVertex());

                next.enqueue(it->getData());
                visited.insert(it->getData());
            }
        }
    }

    paths.display_edge_list();

    vertex = paths.find(toVertex->getVertex());

    LList<T> path;

    while (true)
    {
        path.insertHead(vertex->getVertex());
        if (vertex->getVertex() == fromVertex->getVertex())
        {
            break;
        }
        vertex = vertex->getAdjacency().begin()->getData();
    }

    return path;
}

#endif