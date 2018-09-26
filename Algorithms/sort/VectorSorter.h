#include <vector>
#include <string>

#pragma once

using namespace std;

class VectorSorter {

public:

    virtual string AlgorithmName() = 0;

    virtual void operator()(vector<int>& Data) = 0;

};
