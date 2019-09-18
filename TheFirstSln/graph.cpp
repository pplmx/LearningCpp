#pragma once
#include "graph.h"
#include <iostream>
#include <algorithm>
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

GraphUtils::GraphUtils(int edge[][3])
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
    return vertex_set;
}

set<tuple<int, int>> GraphUtils::get_edge_set(int (*edge)[2])
{

    return set<tuple<int, int>>();
}

void myfunc(tuple<int, int> i)
{ // function:
    std::cout << ' ' << get<0>(i) << ' ' << get<1>(i) << std::endl;
}

int main()
{
    set<tuple<int, int>> edge_set;
    edge_set.insert(make_tuple(2, 3));
    edge_set.insert(make_tuple(1, 2));
    edge_set.insert(make_tuple(2, 1));
    edge_set.insert(make_tuple(2, 3));
    for_each(edge_set.begin(), edge_set.end(), myfunc);
    return 0;
}
