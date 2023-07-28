#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include "../linkedlist/linkedlist.hpp"
#include "../set/set.hpp"

template <typename T>
class GraphVertex
{
public:
    GraphVertex(T data) : data(new T(data)) {}
    T getData() { return *data; }
    bool operator<(GraphVertex<T> rhs)
    {
        return this->getData() < rhs->getData();
    }
    ~GraphVertex()
    {
        delete data;
    }

private:
    T *data;
};

template <typename T>
class AdjacencyList
{
public:
    AdjacencyList(T data) : vertex(new GraphVertex<T>(data)), adj(new Set<GraphVertex<T> *>()) {}
    GraphVertex<T> *&getVertex() { return vertex; }
    Set<GraphVertex<T> *> *&getAdjacency() { return adj; }
    void addAdjacent(GraphVertex<T> *neighbor)
    {
        adj->insert(neighbor);
    }
    bool operator<(AdjacencyList<T> rhs)
    {
        return this->getVertex()->getData() < rhs.getVertex()->getData();
    }
    bool operator>(AdjacencyList<T> rhs)
    {
        return this->getVertex()->getData() > rhs.getVertex()->getData();
    }
    bool operator==(AdjacencyList<T> rhs)
    {
        return this->getVertex()->getData() == rhs.getVertex()->getData();
    }
    ~AdjacencyList() {}

private:
    GraphVertex<T> *vertex;
    Set<GraphVertex<T> *> *adj;
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
        adjlists.insert(AdjacencyList<T>(data));
        vcnt += 1;
    }
    void addEdge(T fromNode, T toNode)
    {
        AdjacencyList<T> *fromAdjList = find(fromNode);
        fromAdjList->addAdjacent(find(toNode)->getVertex());
        ecnt += 1;
    }
    void display()
    {
        typename Set<AdjacencyList<T>>::iterator vert;
        typename Set<GraphVertex<T> *>::iterator adj;

        for (vert = adjlists.begin(); vert != adjlists.end(); vert++)
        {
            for (adj = vert->getData().getAdjacency()->begin(); adj != vert->getData().getAdjacency()->end(); adj++)
            {
                std::cout << vert->getData().getVertex()->getData() << "," << adj->getData()->getData() << std::endl;
            }
        }
    }
    AdjacencyList<T> *find(T data)
    {
        return &adjlists.find(AdjacencyList<T>(data))->getData();
    }

    ~Graph() {}

private:
    int vcnt;
    int ecnt;

    Set<AdjacencyList<T>> adjlists;
};

#endif