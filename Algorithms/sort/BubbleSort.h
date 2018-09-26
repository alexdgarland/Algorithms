#include "VectorSorter.h"

#pragma once

class BubbleSorter : public VectorSorter {

public:

    string AlgorithmName() {
        return "Bubble Sort";
    }

    void operator()(vector<int>& Data) {

        int i, j;

        for (i = 0; i < (Data.size() - 1); i++)
        {
            for (j = (Data.size() - 1); j > i; j--)
            {
                if (Data[j] < Data[j - 1])
                {
                    swap(Data[j], Data[j - 1]);
                }
            }
        }

    }

};
