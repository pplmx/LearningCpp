#pragma once
#include "graph.h"
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;
GraphUtils::GraphUtils(int edge[][2])
{
    size_t length = len(edge);
    this->graph->vertex_num = GraphUtils::get_vertex_set(edge).size();
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            int idx = locate_vertex(this->graph, edge[i][j]);
            if (j == 0) {
                this->graph->list[idx].data = edge[i][j];
                this->graph->list[idx].first_edge->u = edge[i][j];
                // this->graph->list->first_edge->u_next_edge = ? ;
            } else {
                this->graph->list[idx].first_edge->v = edge[i][j];
                // this->graph->list->first_edge->v_next_edge = ? ;
            }
        }
    }
}

GraphUtils::GraphUtils(double edge[][3])
{
}

GraphUtils::GraphUtils(const GraphUtils& obj)
{
}

int GraphUtils::locate_vertex(Graph* g, VertexType v)
{
    for (size_t i = 0; i < g->vertex_num; i++) {
        if (g->list[i].data == v) {
            return i;
        }
    }
    return -1;
}

set<int> GraphUtils::get_vertex_set(int (*edge)[2])
{
    set<int> vertex_set;
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            vertex_set.insert(edge[i][j]);
        }
    }
    this->vertex_set = vertex_set;
    return vertex_set;
}

set<int> GraphUtils::get_vertex_set(double (*edge)[3])
{
    set<int> vertex_set;
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < 2; j++) {
            vertex_set.insert(edge[i][j]);
        }
    }
    this->vertex_set = vertex_set;
    return vertex_set;
}

set<edge_tuple> GraphUtils::get_edge_set(int (*edge)[2])
{
    set<edge_tuple> edge_set;
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        edge_set.insert(make_tuple(edge[i][0], edge[i][1]));
    }
    this->edge_set = edge_set;
    return edge_set;
}

set<edge_w_tuple> GraphUtils::get_edge_set(double (*edge)[3])
{
    set<edge_w_tuple> edge_set;
    size_t length = len(edge);
    for (size_t i = 0; i < length; i++) {
        edge_set.insert(make_tuple(edge[i][0], edge[i][1], edge[i][2]));
    }
    this->edge_w_set = edge_set;
    return edge_set;
}

void myfunc(tuple<int, int, double> i)
{
    std::cout << ' ' << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << std::endl;
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
    for_each(edge_set.begin(), edge_set.end(), myfunc);
    return 0;
}
