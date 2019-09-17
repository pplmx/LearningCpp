#pragma once

typedef int VertexType;

/*
undirected graph
implemented by adjacency multilist
*/
struct Graph {
    int vertex_num, edge_num;
    Adj_multi_list list;
};


class GraphUtils {
public:
    // only contains the two nodes of edge
    GraphUtils(int edge[][2]);
    // except two nodes, contains the weight of edge
    GraphUtils(int edge[][3]);
    GraphUtils(const GraphUtils& obj);
    ~GraphUtils();

private:
    Graph *graph;
};

GraphUtils::GraphUtils(int edge[][2])
{
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            this->graph->list->first_edge->u = edge[i][j];
        }
    }
}

GraphUtils::GraphUtils(int edge[][3])
{
}


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

template <typename T>
int len(T& arr)
{
    return sizeof arr / sizeof arr[0]
}
