#pragma once
#include <set>
#include <tuple>
using namespace std;

typedef int VertexType;

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the two node of an edge
    int u, v;
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
    GraphUtils(int edge[][2]);
    // except two nodes, contains the weight of edge
    GraphUtils(double edge[][3]);
    GraphUtils(const GraphUtils& obj);
    ~GraphUtils();

private:
    Graph* graph;
    set<int> get_vertex_set(int (*edge)[2]);
    set<tuple<int, int>> get_edge_set(int (*edge)[2]);

    set<int> get_vertex_set(double (*edge)[3]);
    set<tuple<int, int, double>> get_edge_set(double (*edge)[3]);
    int locate_vertex(Graph* g, VertexType v);
};

bool operator==(tuple<int, int, double> t1, tuple<int, int, double> t2)
{
    if (get<0>(t1) == get<0>(t2) && get<1>(t1) == get<1>(t2)) {
        // (1, 2, 0.4) == (1, 2, 0.6)
        return true;
    } else if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2, 0.4) == (2, 1, 0.6)
        return true;
    }
    return false;
}

template <typename T>
bool operator==(const tuple<T, T>& t1, const tuple<T, T>& t2)
{
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return true;
    } else if (get<0>(t1) == get<0>(t2) && get<1>(t1) == get<1>(t2)) {
        // (1, 2) == (1, 2)
        return true;
    }
    return false;
}

template <typename T>
bool operator<(const tuple<T, T>& t1, const tuple<T, T>& t2)
{
    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) > get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) > get<0>(t2);
}

// get the length of array
template <typename T>
size_t len(T& arr)
{
    return sizeof arr / sizeof arr[0];
}
