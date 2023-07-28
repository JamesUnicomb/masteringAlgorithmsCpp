#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 2);
    graph.addEdge(3, 4);
    graph.addEdge(5, 1);

    cout << "edge list: " << endl;
    graph.display();

    GraphVertex<int> *g = graph.find(3)->getVertex();

    cout << "find(3) : " << g->getData() << " at address (" << g << ")" << endl;
    cout << "vertex count = " << graph.getVertexCount() << endl;
    cout << "edge count = " << graph.getEdgeCount() << endl;
}