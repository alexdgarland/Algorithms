#include <stdlib.h>
#include "MergeSort.h"

void MergeSort(std::vector<int> Data)
{
    InnerMergeSort(Data.data(), Data.size());
}

// TODO - basically just wrapping an array implementation with a thin layer that uses a vector for consistency with other algos
// TODO - need to switch over to using a vector for the actual impl when I have time

void InnerMergeSort(int* Data, int DataSize)
{
    if (DataSize > 1)  // If DataSize is 1, do nothing... single element cannot be out of order
    {
        int splitPoint = DataSize / 2;
        /* Recursive merge sort of each half */
        InnerMergeSort(Data, splitPoint);
        InnerMergeSort(Data + splitPoint, DataSize - splitPoint);
        /* Merge sorted parts using separate helper function */
        MergeSortedSections(Data, DataSize, splitPoint);
    }

}

void MergeSortedSections(int* ArrayToSort, int ArraySize, int SplitPoint)
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
        // Bounds-checking on arrays is slightly more complex than using "sentinel" value as per Cormen et al,
        // but safer/ more correct in practice - ensures we can handle full range of integer values.
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

    // Cleanup
    free(leftSection);
    free(rightSection);

}
