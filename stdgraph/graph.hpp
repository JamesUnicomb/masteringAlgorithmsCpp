#ifndef __STDGRAPH_HPP__
#define __STDGRAPH_HPP__

#include <iostream>
#include <set>
#include <map>

template <typename T>
class AdjacencyList
{
public:
    AdjacencyList(T data) : vertex(new T(data)), adjlist() {}
    T *vertex;
    std::set<AdjacencyList<T> *> adjlist;
};

template <typename T>
class Graph
{
public:
    void addVertex(T data)
    {
        adjlists[data] = new AdjacencyList<T>(data);
    }
    void addEdge(T from, T to)
    {
        adjlists[from]->adjlist.insert(adjlists[to]);
    }
    void display()
    {
        typename std::map<T, AdjacencyList<T> *>::iterator vertexIt;
        typename std::set<AdjacencyList<T> *>::iterator edgeIt;

        for (vertexIt = adjlists.begin(); vertexIt != adjlists.end(); vertexIt++)
        {
            for (edgeIt = vertexIt->second->adjlist.begin(); edgeIt != vertexIt->second->adjlist.end(); edgeIt++)
            {
                std::cout << vertexIt->first << "," << *(*edgeIt)->vertex << std::endl;
            }
        }
    }

    std::map<T, AdjacencyList<T> *> adjlists;
};

#endif
