#include "VectorSorter.h"

#pragma once

class InsertionSorter : public VectorSorter {

public:

    string AlgorithmName() {
        return "Insertion Sort";
    }

    void operator()(vector<int>& Data) {

        int i, j;

        for (i = 1; i < Data.size(); i++)
        {
            for (j = i; j > 0 && Data[j] < Data[j - 1]; j--)
            {
                swap(Data[j], Data[j - 1]);
            }
        }

    }

};
