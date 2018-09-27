#include "VectorSorter.h"

#pragma once

class MergeSorter : public VectorSorter {

public:

    string AlgorithmName() {
        return "Merge Sort";
    }

    void operator()(vector<int>& Data) {

        MergeSort(Data.data(), Data.size());
    
    }

    static void MergeSort(int* Data, int DataSize)
    {

        // If DataSize is 1, do nothing... single element cannot be out of order
        if (DataSize > 1)
        {
            int splitPoint = DataSize / 2;

            // Recursive merge sort of each half
            MergeSort(Data, splitPoint);
            MergeSort(Data + splitPoint, DataSize - splitPoint);

            MergeSortedSections(Data, DataSize, splitPoint);
        }

    }

    static void MergeSortedSections(int* Data, int ArraySize, int SplitPoint)
    {
        int i, leftIndex = 0, rightIndex = 0;
        
        vector<int> leftTemp = vector<int>(&Data[0], &Data[SplitPoint]);
        vector<int> rightTemp = vector<int>(&Data[SplitPoint], &Data[ArraySize]);

        for (i = 0; i < ArraySize; i++)
        {
            if (rightIndex >= rightTemp.size() ||
                (leftIndex < leftTemp.size() &&
                    leftTemp[leftIndex] < rightTemp[rightIndex]))
            {
                Data[i] = leftTemp.at(leftIndex++);
            }
            else
            {
                Data[i] = rightTemp.at(rightIndex++);
            }
        }

    }

};
