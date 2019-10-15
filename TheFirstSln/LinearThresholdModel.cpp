#pragma once
#include "graph.h"

class LTModel {
public:
    LTModel(GraphUtils* graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps = 0);
    LTModel(const LTModel& obj);
    ~LTModel();

private:
    GraphUtils* graph;
    set<VertexType> seeds;
    set<VertexType> burning_seq;
    int steps = 0;

    void init_model();
};

LTModel::LTModel(GraphUtils* graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps)
{
    this->graph = graph;
}

LTModel::LTModel(const LTModel& obj)
{
}

LTModel::~LTModel()
{
}

void LTModel::init_model()
{
}
