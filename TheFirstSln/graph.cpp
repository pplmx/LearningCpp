#pragma once
#include "graph.h"
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

GraphUtils::GraphUtils()
{
}

GraphUtils::GraphUtils(set<edge_tuple> edge_set)
{
    // init edge_set(to remove the repeated edge)
    this->set_edge_set(edge_set);

    // init vertex_set
    this->set_vertex_set(this->edge_set);

    // init graph
    this->graph = new Graph;
    this->graph->vertex_num = this->vertex_set.size();
    this->graph->edge_num = this->edge_set.size();
    this->graph->list = new Vertex[this->graph->vertex_num];

    // init adjacency multi-list
    // init all vertices's struct in adj_multi_list
    size_t idx = 0;
    for (auto vertex : this->vertex_set) {
        // C6386 warning, how to fix it?
        this->graph->list[idx].data = vertex;
        this->graph->list[idx].first_edge = nullptr;
        this->graph->list[idx].threshold = 0;
        idx++;
    }
    // init all edges' struct in adj_multi_list
    VertexType u, v;
    int u_idx, v_idx;
    for (auto edge : this->edge_set) {
        Edge* edge_ptr = new Edge;
        u = get<0>(edge);
        v = get<1>(edge);

        // find the index of a node in adj_multi_list
        u_idx = this->locate_vertex(this->graph, u);
        v_idx = this->locate_vertex(this->graph, v);

        // init edge to be not visited and set the weight of a edge
        edge_ptr->is_visited = false;
        edge_ptr->weight = get<2>(edge);

        edge_ptr->u_idx = u_idx;
        edge_ptr->u_next_edge = this->graph->list[u_idx].first_edge;
        // point to this new edge on u
        this->graph->list[u_idx].first_edge = edge_ptr;

        edge_ptr->v_idx = v_idx;
        edge_ptr->v_next_edge = this->graph->list[v_idx].first_edge;
        // point to this new edge on v
        this->graph->list[v_idx].first_edge = edge_ptr;
    }
}

GraphUtils::GraphUtils(const GraphUtils& obj)
{
    // allocate the memory
    this->graph = new Graph;
    // copy the value
    *(this->graph) = *obj.graph;
}

set<VertexType> GraphUtils::get_vertex_set()
{
    return this->vertex_set;
}

set<edge_tuple> GraphUtils::get_edge_set()
{
    return this->edge_set;
}

set<VertexType> GraphUtils::get_neighbor_node_set(VertexType data)
{
    int data_idx = this->locate_vertex(this->graph, data);
    set<VertexType> node_set;
    Edge* edge = this->graph->list[data_idx].first_edge;
    VertexType u, v;
    while (edge != nullptr) {
        u = this->graph->list[edge->u_idx].data;
        v = this->graph->list[edge->v_idx].data;
        if (u == data) {
            node_set.insert(v);
            edge = edge->u_next_edge;
        }
        if (v == data) {
            node_set.insert(u);
            edge = edge->v_next_edge;
        }
    }
    return node_set;
}

set<edge_tuple> GraphUtils::get_neighbor_edge_set(VertexType data)
{
    return set<edge_tuple>();
}

int GraphUtils::get_degree(VertexType data)
{
    return this->get_neighbor_node_set(data).size();
}

GraphUtils::~GraphUtils()
{
    delete graph;
}

int GraphUtils::locate_vertex(Graph* g, VertexType v)
{
    for (int i = 0; i < g->vertex_num; i++) {
        if (g->list[i].data == v) {
            return i;
        }
    }
    return -1;
}

void GraphUtils::set_vertex_set(set<edge_tuple> edge_set)
{
    for_each(edge_set.begin(), edge_set.end(), [this](const auto& edge) {
        this->vertex_set.insert(get<0>(edge));
        this->vertex_set.insert(get<1>(edge));
    });
}

void GraphUtils::set_edge_set(set<edge_tuple> edge_set)
{
    for (auto edge : edge_set) {
        this->edge_set.insert(edge);
    }
}

int main()
{
    // use the compare function of set
    // set<tuple<int, int>, decltype(&edge_compare)> edge_set(&edge_compare);
    /*set<tuple<VertexType, VertexType>> edge_set;
    edge_set.insert(make_tuple(2, 3));
    edge_set.insert(make_tuple(1, 2));
    edge_set.insert(make_tuple(2, 1));
    edge_set.insert(make_tuple(2, 3));
    edge_set.insert(make_tuple(3, 4));
    edge_set.insert(make_tuple(4, 5));
    edge_set.insert(make_tuple(2, 6));*/

    set<edge_tuple> edge_set;
    edge_set.insert(make_tuple(2, 3, 0.2));
    edge_set.insert(make_tuple(1, 2, 0.4));
    edge_set.insert(make_tuple(2, 1, 0.1));
    edge_set.insert(make_tuple(2, 3, 0.7));
    edge_set.insert(make_tuple(3, 4, 0.9));
    edge_set.insert(make_tuple(4, 5, 0.1));
    edge_set.insert(make_tuple(2, 6, 0.5));

    GraphUtils graph(edge_set);
    set<VertexType> vs = graph.get_vertex_set();
    // set<edge_tuple> es = graph.get_edge_set();
    set<edge_tuple> es = graph.get_edge_set();
    set<VertexType> nbr_node = graph.get_neighbor_node_set(2);
    for_each(vs.begin(), vs.end(), [](const auto& vertex) {
        std::cout << vertex << ", ";
    });
    std::cout << std::endl;
    for_each(es.begin(), es.end(), [](const auto& edge) {
        // std::cout << "(" << get<0>(edge) << ", " << get<1>(edge) << ")" << std::endl;
        std::cout << "(" << get<0>(edge) << ", " << get<1>(edge) << ", " << get<2>(edge) << ")" << std::endl;
    });
    for_each(nbr_node.begin(), nbr_node.end(), [](const auto& vertex) {
        std::cout << vertex << ", ";
    });
    std::cout << std::endl;

    return 0;
}
