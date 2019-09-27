#pragma once
#include <set>
#include <tuple>

typedef long VertexType;

namespace std {
// a edge without weight
typedef tuple<VertexType, VertexType> edge_tuple;
// a edge with weight
typedef tuple<VertexType, VertexType, double> edge_w_tuple;
bool operator<(const edge_tuple& t1, const edge_tuple& t2)
{
    // remove the repeated
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return false;
    }

    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) < get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) < get<0>(t2);
}

bool operator<(const edge_w_tuple& t1, const edge_w_tuple& t2)
{
    // remove the repeated
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return false;
    }

    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) < get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) < get<0>(t2);
}
}
using namespace std;

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the index of two node of an edge in adj_multi_list
    int u_idx, v_idx;
    Edge *u_next_edge, *v_next_edge;
    double weight;
};

typedef struct Vertex {
    VertexType data;
    Edge* first_edge;
    double threshold;
} * Adj_multi_list;

/*
undirected graph
implemented by adjacency multi-list
*/
struct Graph {
    size_t vertex_num, edge_num;
    Adj_multi_list list;
};

class GraphUtils {
public:
    // only contains the two nodes of edge
    GraphUtils(set<edge_tuple> edge_set);
    // except two nodes, contains the weight of edge
    GraphUtils(set<edge_w_tuple> edge_set);
    GraphUtils(const GraphUtils& obj);

    // get all vertices
    set<VertexType> get_vertex_set();
    // get all edges
    set<edge_tuple> get_edge_set();
    set<edge_w_tuple> get_edge_w_set();

    // get the neighbor nodes of a node
    set<VertexType> get_neighbor_node_set(VertexType data);
    // get the neighbor edges of a node
    set<edge_tuple> get_neighbor_edge_set(VertexType data);
    set<edge_w_tuple> get_neighbor_edge_w_set(VertexType data);

    // get the degree of a node
    int get_degree(VertexType data);

    ~GraphUtils();

private:
    Graph* graph;
    set<VertexType> vertex_set;
    set<edge_tuple> edge_set;
    set<edge_w_tuple> edge_w_set;

    void set_vertex_set(set<edge_tuple> edge_set);
    void set_vertex_set(set<edge_w_tuple> edge_set);

    void set_edge_set(set<edge_tuple> edge_set);
    void set_edge_set(set<edge_w_tuple> edge_set);
    int locate_vertex(Graph* g, VertexType v);
};

bool edge_compare(const tuple<int, int>& t1, const tuple<int, int>& t2)
{

    // remove the repeated
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return false;
    }

    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) < get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) < get<0>(t2);
}

bool edge_w_compare(const tuple<int, int, double>& t1, const tuple<int, int, double>& t2)
{

    // remove the repeated
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return false;
    }

    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) < get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) < get<0>(t2);
}

// get the length of array
template <typename T>
const size_t len(const T& arr)
{
    return sizeof arr / sizeof arr[0];
}
