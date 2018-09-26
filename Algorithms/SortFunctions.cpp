#include <stdlib.h>
#include <vector>

#include "SortFunctions.h"

void InsertionSort(std::vector<int>& Data)
{
    int i, j;
    
    for (i = 1; i < Data.size(); i++)
    {
        for(j = i; j > 0 && Data[j] < Data[j-1]; j--)
        {
            SwapArrayElements(Data, j, j-1);
        }
    }

}

void SelectionSort(std::vector<int>& Data)
{

    int i, indexSmallestRemaining;
    
    for(i = 0; i < (Data.size() -1); i++)
    {

        // Hidden O(n^2) as we're also looping within the inner function
        indexSmallestRemaining = FindIndexOfSmallestElement(Data, i + 1, Data.size() - 1);
    
        if(Data[indexSmallestRemaining] < Data[i])
        {
            SwapArrayElements(Data, indexSmallestRemaining, i);
        }
    }

};

void BubbleSort(std::vector<int>& Data)
{
    int i, j;

    for(i = 0; i < (Data.size() - 1); i++)
    {
        for(j = (Data.size() - 1); j > i; j--)
        {
            if(Data[j] < Data[j-1])
            {
                std::swap(Data[j], Data[j-1]);
            }
        }
    }

}

int FindIndexOfSmallestElement(const std::vector<int> Data, const int StartIndex, const int EndIndex)
{
    int indexOfSmallest = StartIndex;
    
    int i;
    for(i = StartIndex +1; i < EndIndex; i++)
    {
        if(Data[i] < Data[indexOfSmallest])
        {
            indexOfSmallest = i;
        }
    }

    return indexOfSmallest;
}

void SwapArrayElements(std::vector<int>& Data, const int Index1, const int Index2)
{
    // TODO - this is now so trivial no point maintaining a separate function
    std::swap(Data[Index1], Data[Index2]);
}
