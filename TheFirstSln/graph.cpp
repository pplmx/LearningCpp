#pragma once
#include "graph.h"
#include <iostream>
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

set<pair<int, int>> GraphUtils::get_edge_set(int (*edge)[2])
{

    return set<pair<int, int>>();
}

// get the length of array
template <typename T>
size_t len(T& arr)
{
    return sizeof arr / sizeof arr[0];
}

int main()
{
    set<pair<int, int>> edge_set;
    edge_set.insert(make_pair(2, 3));
    edge_set.insert(make_pair(1, 2));
    edge_set.insert(make_pair(2, 1));
    edge_set.insert(make_pair(2, 3));
    
    return 0;
}
