#include "SearchFunctions.h"

int LinearSearch(const int* ArrayToSearch, const int Length, const int ItemToFind)
{
    int i;
    for (i = 0; i < Length; i++)
    {
        if (ArrayToSearch[i] == ItemToFind) { return i; }
    }
    return -1;
}
 
int BinarySearch(const int* SortedArrayToSearch, const int Length, const int ItemToFind)
{
    int midPoint, midPointValue;
    
    if(Length == 1) { return SortedArrayToSearch[0] == ItemToFind ? 0 : -1; }

    midPoint = Length / 2;
    midPointValue = SortedArrayToSearch[midPoint];

    if(midPointValue == ItemToFind)
    {
        return midPoint;
    }
    else if (midPointValue > ItemToFind)
    {
        return BinarySearch(SortedArrayToSearch, midPoint, ItemToFind);
    }
    else /* Implicitly ...  midPointValue < ItemToFind */
    {
        int recursiveResult = BinarySearch(&(SortedArrayToSearch[midPoint+1]), Length - (midPoint+1), ItemToFind);
        return  (recursiveResult < 0) ? recursiveResult : (recursiveResult + midPoint + 1);
    }
}
