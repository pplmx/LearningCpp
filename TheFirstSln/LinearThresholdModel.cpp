#pragma once

#include "LinearThresholdModel.h"

LTModel::LTModel(UndirectedGraph *graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps) {
    this->graph = graph;
}

LTModel::LTModel(const LTModel &obj) {
    this->graph = new UndirectedGraph;
    *(this->graph) = *obj.graph;
}

LTModel::~LTModel() {
}

set<VertexType> LTModel::find_minimal_dominating_set() {
    set<VertexType> minimal_dominating_set;
    set<VertexType> dominated_set;
    return minimal_dominating_set;
}
