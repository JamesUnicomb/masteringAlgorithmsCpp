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

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(3, 2);
    graph.addEdge(3, 4);
    graph.addEdge(4, 3);

    cout << "edge list: " << endl;
    graph.display_edge_list();

    cout << "vertex count = " << graph.getVertexCount() << endl;
    cout << "edge count = " << graph.getEdgeCount() << endl;

    if (is_connected(graph.find(1), graph.find(3)))
    {
        cout << "path found" << endl;
    }
    else
    {
        cout << "path not found" << endl;
    }

    if (is_cyclic(graph))
    {
        cout << "is cyclic" << endl;
    }
    else
    {
        cout << "is not cyclic" << endl;
    }

    find_shortest_path(graph.find(1), graph.find(4)).display();
}