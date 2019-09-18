#pragma once
#include <set>
using namespace std;
typedef int VertexType;
typedef Vertex* Adj_multi_list;
/*
undirected graph
implemented by adjacency multi-list
*/
struct Graph {
    size_t vertex_num, edge_num;
    Adj_multi_list list;
};

struct Vertex {
    VertexType data;
    Edge* first_edge;
    double threshold;
};

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the two node of an edge
    int u, v;
    Edge *u_next_edge, *v_next_edge;
    double weight;
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
    Graph* graph;
    set<int> get_vertex_set(int (*edge)[2]);
    set<pair<int, int>> get_edge_set(int (*edge)[2]);

    set<int> get_vertex_set(double (*edge)[3]);
    set<tuple<int, int, double>> get_edge_set(double (*edge)[3]);
    int locate_vertex(Graph* g, VertexType v);
};
