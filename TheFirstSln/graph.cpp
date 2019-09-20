#pragma once
#include "graph.h"
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;
GraphUtils::GraphUtils(set<edge_tuple> edge_set)
{
    // init edge_set(to remove the repeated edge)
    this->set_edge_set(edge_set);
    // init edge_w_set as empty set
    this->edge_w_set = set<edge_w_tuple>();

    // init vertex_set
    this->set_vertex_set(this->edge_set);

    // init graph
    this->graph->vertex_num = this->vertex_set.size();
    this->graph->edge_num = this->edge_set.size();

    size_t idx = 0;
    for (auto vertex : this->vertex_set) {
        this->graph->list[idx].data = vertex;
        this->graph->list[idx].first_edge = new Edge;
        this->graph->list[idx].threshold = 0;
        idx++;
    }
}

GraphUtils::GraphUtils(set<edge_w_tuple> edge_set)
{
    // init edge_w_set(to remove the repeated edge)
    this->set_edge_set(edge_set);
    // init edge_set as empty set
    this->edge_set = set<edge_tuple>();

    // init vertex_set
    this->set_vertex_set(this->edge_w_set);

    // init graph
    this->graph->vertex_num = this->vertex_set.size();
    this->graph->edge_num = this->edge_w_set.size();
}

GraphUtils::GraphUtils(const GraphUtils& obj)
{
}

set<int> GraphUtils::get_vertex_set()
{
    return this->vertex_set;
}

set<edge_tuple> GraphUtils::get_edge_set()
{
    return this->edge_set;
}

set<edge_w_tuple> GraphUtils::get_edge_w_set()
{
    return this->edge_w_set;
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
    for (auto edge : edge_set) {
        this->vertex_set.insert(get<0>(edge));
        this->vertex_set.insert(get<1>(edge));
    }
}

void GraphUtils::set_vertex_set(set<edge_w_tuple> edge_set)
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

void GraphUtils::set_edge_set(set<edge_w_tuple> edge_set)
{
    for (auto edge : edge_set) {
        this->edge_w_set.insert(edge);
    }
}

int main()
{
    // set<tuple<int, int>, decltype(&edge_compare)> edge_set(&edge_compare);
    // set<edge_tuple> edge_set;
    set<edge_w_tuple> edge_set;
    edge_set.insert(make_tuple(2, 3, 0.2));

    edge_set.insert(make_tuple(1, 2, 0.4));

    edge_set.insert(make_tuple(2, 1, 0.9));

    edge_set.insert(make_tuple(2, 3, 0.5));
    for_each(edge_set.begin(), edge_set.end(), [](const auto& edge) {
        std::cout << ' ' << get<0>(edge) << ' ' << get<1>(edge) << ' ' << get<2>(edge) << std::endl;
    });
    return 0;
}
