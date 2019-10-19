#pragma once
#include "LinearThresholdModel.h"

LTModel::LTModel(GraphUtils* graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps)
{
    this->graph = graph;
}

LTModel::LTModel(const LTModel& obj)
{
    this->graph = new GraphUtils;
    *(this->graph) = *obj.graph;
}

LTModel::~LTModel()
{
}

set<VertexType> LTModel::find_minimal_dominating_set()
{
    return set<VertexType>();
}
