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
    graph.addVertex(6);
    graph.addVertex(7);

    graph.addEdge(graph.find(1), graph.find(2));
    graph.addEdge(graph.find(2), graph.find(1));
    graph.addEdge(graph.find(1), graph.find(3));
    graph.addEdge(graph.find(3), graph.find(1));
    graph.addEdge(graph.find(3), graph.find(4));
    graph.addEdge(graph.find(4), graph.find(3));
    graph.addEdge(graph.find(5), graph.find(4));
    graph.addEdge(graph.find(4), graph.find(5));
    graph.addEdge(graph.find(6), graph.find(4));
    graph.addEdge(graph.find(4), graph.find(6));
    graph.addEdge(graph.find(6), graph.find(7));
    graph.addEdge(graph.find(7), graph.find(6));

    cout << "edge list: " << endl;
    graph.display();

    cout << "vertex count = " << graph.getVertexCount() << endl;
    cout << "edge count = " << graph.getEdgeCount() << endl;

    get_paths(graph.find(1), graph.find(4));
    get_paths(graph.find(1), graph.find(7));
}