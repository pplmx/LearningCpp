#pragma once

#include <iostream>
#include "graph.h"
using namespace std;

set<VertexType> seeds_default;

class LTModel {
public:
    LTModel(GraphUtils* graph, set<VertexType> seeds, set<VertexType> burning_seq, int steps=0);
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
    this->graph = new GraphUtils;
    *(this->graph) = *obj.graph;
}

LTModel::~LTModel()
{
}

void LTModel::init_model()
{
}
