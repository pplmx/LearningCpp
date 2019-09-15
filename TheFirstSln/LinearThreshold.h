/*
undirected graph
implemented by adjacency multilist
*/
class Graph {
public:
    // only contains the two nodes of edge
    Graph(int edge[][2]);
    // except two nodes, contains the weight of edge
    Graph(int edge[][3]);
    ~Graph();

private:
    int vertex_num, edge_num;
    Vertex* adj_multi_list;
};

class Digraph {
public:
    Digraph();
    ~Digraph();

private:
};

Digraph::Digraph()
{
}

Digraph::~Digraph()
{
}

Graph::Graph(int edge[][2])
{
}

Graph::Graph(int edge[][3])
{
}

Graph::~Graph()
{
}

/*
directed graph
implemented by orthogonal list
*/
struct DiGraph {
    int vertex_num, edge_num;
    Orthogonal_list list;
};

struct Adjacency_multi_list {
    Vertex* adj_multi_list;
};

struct Orthogonal_list {
};

struct Vertex {
    int v;
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
