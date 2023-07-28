#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include "../linkedlist/linkedlist.hpp"
#include "../set/set.hpp"

template <typename T>
class GraphVertex
{
public:
    GraphVertex(T data) : data(new T(data)) {}
    T getData() { return *data; }

private:
    T *data;
};

template <typename T>
class AdjacencyList
{
public:
    GraphVertex<T> *&getVertex() { return vertex; }

private:
    GraphVertex<T> *vertex;
    Set<GraphVertex<T>> adj;
};

template <typename T>
class Graph
{
public:
    Graph() : vcnt(0), ecnt(0) {}

private:
    int vcnt;
    int ecnt;

    Set<AdjacencyList<T>> adjlists;
};

#endif