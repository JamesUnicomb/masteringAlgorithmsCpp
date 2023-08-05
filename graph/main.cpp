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

    PathExistsPred<int> p(graph.find(3));
    breadth_first_search(graph.find(1), p);
    if (p.pathFound())
    {
        cout << "path found" << endl;
    }
    else
    {
        cout << "path not found" << endl;
    }

    p = PathExistsPred<int>(graph.find(3));
    depth_first_search(graph.find(1), p);
    if (p.pathFound())
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

    // graph.addEdge(graph.find(7), graph.find(5));

    // graph.display();

    // if (is_cyclic(graph))
    // {
    //     cout << "is cyclic" << endl;
    // }
    // else
    // {
    //     cout << "is not cyclic" << endl;
    // }

    find_shortest_path(graph.find(1), graph.find(4)).display();
}