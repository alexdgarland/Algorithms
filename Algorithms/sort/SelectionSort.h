#include "VectorSorter.h"

#pragma once

class SelectionSorter : public VectorSorter {

public:

    string AlgorithmName() {
        return "Selection Sort";
    }

    static int FindIndexOfSmallest(const vector<int> Data, const int StartIndex) {

        int indexOfSmallest = StartIndex;

        int i;

        for (i = StartIndex + 1; i < Data.size(); i++)
        {
            if (Data[i] < Data[indexOfSmallest])
            {
                indexOfSmallest = i;
            }
        }

        return indexOfSmallest;
    
    }

    void operator()(vector<int>& Data) {

        int i, indexSmallestRemaining;

        for (i = 0; i < (Data.size() - 1); i++)
        {

            indexSmallestRemaining = FindIndexOfSmallest(Data, i + 1);

            if (Data[indexSmallestRemaining] < Data[i])
            {
                swap(Data[indexSmallestRemaining], Data[i]);
            }

        }

    }

};
