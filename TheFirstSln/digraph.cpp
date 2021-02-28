#include "base_graph.h"


DirectedGraph::DirectedGraph()
{
}

DirectedGraph::DirectedGraph(set<tuple<VertexInfo, VertexInfo>> arc_set)
{
}

DirectedGraph::DirectedGraph(const DirectedGraph& obj)
{
}

DirectedGraph::~DirectedGraph()
{
}

set<VertexInfo> DirectedGraph::get_vertex_set()
{
    return set<VertexInfo>();
}

set<arc_tuple> DirectedGraph::get_arc_set()
{
    return set<arc_tuple>();
}

int DirectedGraph::get_indegree(VertexInfo data)
{
    return 0;
}

int DirectedGraph::get_outdegree(VertexInfo data)
{
    return 0;
}

void DirectedGraph::set_vertex_set(set<arc_tuple> arc_set)
{
}

void DirectedGraph::set_arc_set(set<arc_tuple> arc_set)
{
}

int DirectedGraph::locate_vertex(DiGraph* g, VertexInfo v)
{
    return 0;
}
