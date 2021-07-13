#pragma once

#include "graph.h"

class LTModel {
public:
    LTModel(UndirectedGraph *graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps = 0);

    LTModel(const LTModel &obj);

    ~LTModel();

    set<VertexType> find_minimal_dominating_set();

private:
    UndirectedGraph *graph;
    set<VertexType> seeds;
    set<VertexType> burning_seq;
    int steps = 0;
};
