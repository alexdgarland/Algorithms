#include "VectorSorter.h"

#pragma once

class MergeSorter : public VectorSorter {

public:

    string AlgorithmName() {
        return "Merge Sort";
    }

    // TODO - basically just wrapping an array implementation with a thin layer that uses a vector for consistency with other algos
    // TODO - need to switch over to using a vector for the actual impl when I have time

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

    static void MergeSortedSections(int* ArrayToSort, int ArraySize, int SplitPoint)
    {
        int i, leftIndex = 0, rightIndex = 0;

        // Set up temporary arrays for each section
        int* leftSection = (int*)malloc(SplitPoint * sizeof(int));
        int rightSectionSize = ArraySize - SplitPoint;
        int* rightSection = (int*)malloc(rightSectionSize * sizeof(int));

        for (i = 0; i < SplitPoint; i++)
        {
            leftSection[i] = ArrayToSort[i];
        }

        for (i = 0; i < rightSectionSize; i++)
        {
            rightSection[i] = ArrayToSort[i + SplitPoint];
        }

        // Merge back to (overwrite) the original array
        for (i = 0; i < ArraySize; i++)
        {

            if (
                rightIndex >= rightSectionSize
                ||
                (
                    leftIndex < SplitPoint
                    &&
                    leftSection[leftIndex] < rightSection[rightIndex]
                    )
                )
            {
                ArrayToSort[i] = leftSection[leftIndex++];
            }
            else
            {
                ArrayToSort[i] = rightSection[rightIndex++];
            }
        }

        free(leftSection);
        free(rightSection);

    }

};
