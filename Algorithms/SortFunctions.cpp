#include "stdafx.h"
#include <stdlib.h>
#include "SortFunctions.h"

 int* InsertionSort(int* ArrayToSort, int ArraySize)
{
    int i, j;
    
    for (i = 1; i < ArraySize; i++)
    {
        for(j = i; j > 0 && ArrayToSort[j] < ArrayToSort[j-1]; j--)
        {
            SwapArrayElements(ArrayToSort, j, j-1);
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

int* BubbleSort(int* ArrayToSort, int ArraySize)
{
    int i, j;

    for(i=0; i<(ArraySize-1); i++)
    {
        for(j=(ArraySize-1); j>i; j--)
        {
            if(ArrayToSort[j] < ArrayToSort[j-1])
            {
                SwapArrayElements(ArrayToSort, j, j-1);
            }
        }
    }
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
