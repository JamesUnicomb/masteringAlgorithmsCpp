#include <iostream>
#include "graph.hpp"

using namespace std;

template <typename T>
class PathExistsPred
{
public:
    PathExistsPred(AdjacencyList<T> *node) : node(node), found(false) {}
    bool pathFound() { return found; }
    void operator()(AdjacencyList<T> *node)
    {
        if (this->node->getVertex() == node->getVertex())
        {
            found = true;
        }
    }

private:
    AdjacencyList<T> *node;
    bool found;
};

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
    graph.addEdge(graph.find(1), graph.find(6));
    graph.addEdge(graph.find(3), graph.find(2));
    graph.addEdge(graph.find(3), graph.find(4));
    graph.addEdge(graph.find(4), graph.find(5));
    graph.addEdge(graph.find(6), graph.find(5));
    graph.addEdge(graph.find(5), graph.find(7));

    cout << "edge list: " << endl;
    graph.display();

    cout << "vertex count = " << graph.getVertexCount() << endl;
    cout << "edge count = " << graph.getEdgeCount() << endl;

    PathExistsPred<int> p(graph.find(3));
    breadth_first_search(graph, graph.find(1), p);
    if (p.pathFound())
    {
        cout << "path found" << endl;
    }
    else
    {
        cout << "path not found" << endl;
    }

    p = PathExistsPred<int>(graph.find(7));
    depth_first_search(graph, graph.find(1), p);
    if (p.pathFound())
    {
        cout << "path found" << endl;
    }
    else
    {
        cout << "path not found" << endl;
    }
}