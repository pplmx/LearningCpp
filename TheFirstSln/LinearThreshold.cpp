#include "LinearThreshold.h"
#include <iostream>
using namespace std;

class LTModel {
public:
    LTModel();
    LTModel(int num);
    LTModel(const LTModel& obj);
    ~LTModel();

private:
    int steps = 0;
    int* seeds;
};

LTModel::LTModel() {
    seeds = new int;
}

LTModel::LTModel(int num) : steps(num) {
    cout << "LTModel is being created now." << endl;
    seeds = new int;
}

LTModel::LTModel(const LTModel& obj) {
    seeds = new int;
    *seeds = *obj.seeds;
}

LTModel::~LTModel() {
    cout << "LTModel is being deleted now." << endl;
    delete seeds;
}
