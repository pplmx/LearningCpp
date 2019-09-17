#pragma once
#include <set>
using namespace std;
typedef int VertexType;
/*
undirected graph
implemented by adjacency multilist
*/
struct Graph {
    size_t vertex_num, edge_num;
    Adj_multi_list list;
};

typedef struct Vertex {
    VertexType data;
    Edge* first_edge;
    double threshold;
} * Adj_multi_list;

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the two node of an edge
    int u, v;
    Edge *u_next_edge, *v_next_edge;
    double weight;
};

// get the length of array
template <typename T>
size_t len(T& arr)
{
    return sizeof arr / sizeof arr[0]
}

class GraphUtils {
public:
    // only contains the two nodes of edge
    GraphUtils(int edge[][2]);
    // except two nodes, contains the weight of edge
    GraphUtils(int edge[][3]);
    GraphUtils(const GraphUtils& obj);
    ~GraphUtils();

private:
    Graph* graph;
    template <typename T>
    size_t get_vertex_num(T (*edge)[2]);
    int locate_vertex(Graph g, VertexType v);
};

GraphUtils::GraphUtils(int edge[][2])
{
    size_t length = len(edge);
    this->graph->vertex_num = GraphUtils::get_vertex_num(edge);
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            if (j == 0) {
                this->graph->list->data = edge[i][j];
                this->graph->list->first_edge->u = edge[i][j];
                // this->graph->list->first_edge->u_next_edge = ? ;
            } else {
                this->graph->list->first_edge->v = edge[i][j];
                // this->graph->list->first_edge->v_next_edge = ? ;
            }
        }
    }
}

GraphUtils::GraphUtils(int edge[][3])
{
}

int GraphUtils::locate_vertex(Graph g, VertexType v)
{
    for (size_t i = 0; i < g.vertex_num; i++) {
        if (g.list[i].data == v) {
            return i;
        }
    }
    return -1;
}

template <typename T>
size_t GraphUtils::get_vertex_num(T (*edge)[2])
{
    set<T> vertex_set;
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            vertex_set.insert(edge[i][j])
        }
    }
    return vertex_set.size();
}
