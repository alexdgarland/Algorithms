#include "stdafx.h"
#include <stdlib.h>
#include "SortFunctions.h"

 int* InsertionSort(int* ArrayToSort, int ArraySize)
{
    int outerIndex, innerIndex;
    
    for (outerIndex = 1; outerIndex < ArraySize; outerIndex++)
    {
        for(innerIndex = outerIndex;
            innerIndex > 0 && ArrayToSort[innerIndex] < ArrayToSort[innerIndex-1];
            innerIndex--)
        {
            SwapArrayElements(ArrayToSort, innerIndex, innerIndex-1);
        }
    }

    return ArrayToSort;
}

int* SelectionSort(int* ArrayToSort, int ArraySize)
{
    int i, indexSmallestRemaining;
    for(i=0; i<(ArraySize-1); i++)
    {
        // Hidden O(n^2) as we're also looping within the inner function
        indexSmallestRemaining = FindIndexOfSmallestElement(ArrayToSort, i+1, ArraySize-1);
        if(ArrayToSort[indexSmallestRemaining] < ArrayToSort[i])
        {
            SwapArrayElements(ArrayToSort, indexSmallestRemaining, i);
        }
    }
    return ArrayToSort;
};

int* MergeSort(int* ArrayToSort, int ArraySize)
{
    if (ArraySize > 1)  // If ArraySize is 1, do nothing... single element cannot be out of order
    {
        int splitPoint = ArraySize / 2;
        /* Recursive merge sort of each half */
        MergeSort(ArrayToSort, splitPoint);
        MergeSort(ArrayToSort + splitPoint, ArraySize - splitPoint);
        /* Merge sorted parts using separate helper function */
        MergeSortedSections(ArrayToSort, ArraySize, splitPoint);
    }

    return ArrayToSort;
}

int* MergeSortedSections(int* ArrayToSort, int ArraySize, int SplitPoint)
{
    int i, leftIndex=0, rightIndex=0;

    // Set up temporary arrays for each section
    int* leftSection=(int*)malloc(SplitPoint*sizeof(int));
    int rightSectionSize = ArraySize-SplitPoint;
    int* rightSection=(int*)malloc(rightSectionSize*sizeof(int));    
    for(i=0; i<SplitPoint; i++)
    {
        leftSection[i] = ArrayToSort[i];
    }
    for(i=0; i<rightSectionSize; i++)
    {
        rightSection[i] = ArrayToSort[i+SplitPoint];
    }

    // Merge back to (overwrite) the original array
    for(i=0; i<ArraySize; i++)
    {
        // Bounds-checking on arrays is slightly more complex than using "sentinel" value as per Cormen et al,
        // but safer/ more correct in practice - ensures we can handle full range of integer values.
        if(rightIndex >= rightSectionSize || 
                (
                (leftIndex < SplitPoint) &&
                (leftSection[leftIndex] < rightSection[rightIndex])
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

    return ArrayToSort;
}

int FindIndexOfSmallestElement(const int* Array, const int StartIndex, const int EndIndex)
{
    int indexSmallestValue = StartIndex;
    int i;
    for(i = StartIndex +1; i <= EndIndex; i++)
    {
        if(Array[i] < Array[indexSmallestValue])
        {
            indexSmallestValue = i;
        }
    }
    return indexSmallestValue;
}

int* SwapArrayElements(int* ArrayToChange, int ElemIndex1, int ElemIndex2)
{
    int temp = ArrayToChange[ElemIndex1];
    ArrayToChange[ElemIndex1] = ArrayToChange[ElemIndex2];
    ArrayToChange[ElemIndex2] = temp;
    return ArrayToChange;
}
