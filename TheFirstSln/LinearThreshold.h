
/*
undirected graph
implemented by adjacency multilist
*/
struct Graph {
    int vertex_num, edge_num;
    Adjacency_multi_list list;
};

/*
directed graph
implemented by orthogonal list
*/
struct DiGraph {
    int vertex_num, edge_num;
    Orthogonal_list list;
};

struct Adjacency_multi_list {
};

struct Orthogonal_list {
};

struct Vertex {
    double threshold;
    Edge* first_link;
};

struct Edge {
    // mark that whether an edge is visited
    bool is_visited;
    // the two node of an edge
    int u, v;
    Edge *u_link, *v_link;
    double weight;
};
