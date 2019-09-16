#pragma once

typedef int VertexType;

class GraphUtils {
public:
    // only contains the two nodes of edge
    GraphUtils(int edge[][2]);
    // except two nodes, contains the weight of edge
    GraphUtils(int edge[][3]);
    ~GraphUtils();

private:
    int vertex_num, edge_num;
    Vertex* adj_multi_list;
};

/*
undirected graph
implemented by adjacency multilist
*/
struct Graph {
    int vertex_num, edge_num;
    Adjacency_multi_list list;
};

struct Adjacency_multi_list {
    Vertex* adj_multi_list;
};

struct Vertex {
    VertexType v;
    Edge* first_arc;
    double threshold;
};

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the two node of an edge
    int u, v;
    Edge *u_next_arc, *v_next_arc;
    double weight;
};
