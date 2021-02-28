#pragma once

#include <set>
#include <tuple>

namespace std {
    typedef int VertexInfo;
    // an edge with weight
    typedef tuple<VertexInfo, VertexInfo, double> edge_tuple;
    // an arc with weight
    typedef tuple<VertexInfo, VertexInfo, double> arc_tuple;
}
using namespace std;

struct Arc {
    double weight;
    // the two indexes of this arc's vertices 
    int tail_arc_idx, head_arc_idx;
    Arc* head_link, * tail_link;
};

typedef struct Vertex {
    VertexInfo data;
    Arc* first_in;
    Arc* first_out;
} *Orthogonal_List;

struct Edge {
    bool is_visited;
    double weight;
    // u, v mean the two nodes of this edge
    int u_idx, v_idx;
    Edge* u_next_edge, * v_next_edge;
};

typedef struct Node {
    VertexInfo data;
    Edge* first_edge;
} *Adj_Multi_List;

struct UnGraph {
    int vertex_num, edge_num;
    Adj_Multi_List list;
};

struct DiGraph {
    int vertex_num, arc_num;
    Orthogonal_List list;
};

class DirectedGraph {
public:
    DirectedGraph();
    DirectedGraph(set<tuple<VertexInfo, VertexInfo>> arc_set);
    DirectedGraph(set<edge_tuple> edge_set);
    DirectedGraph(const DirectedGraph& obj);
    ~DirectedGraph();

    // get all vertices
    set<VertexInfo> get_vertex_set();
    // get all arcs
    set<arc_tuple> get_arc_set();

    // get the indegree and outdegree of a node
    int get_indegree(VertexInfo data);
    int get_outdegree(VertexInfo data);

private:
    DiGraph* graph;
    set<VertexInfo> vertex_set;
    set<arc_tuple> arc_set;

    void set_vertex_set(set<arc_tuple> arc_set);
    void set_arc_set(set<arc_tuple> arc_set);
    int locate_vertex(DiGraph* g, VertexInfo v);
};
