#include "SearchFunctions.h"

int LinearSearch(const vector<int> Data, const int ItemToFind)
{
    int i;

    for (i = 0; i < Data.size(); i++)
    {
        if (Data[i] == ItemToFind) {
            return i;
        }
    }

    return -1;
}

int BinarySearch(const vector<int> Data, const int ItemToFind) {

    return BinarySearch(Data, ItemToFind, 0, Data.size() -1);

}

int BinarySearch(const vector<int> Data, const int ItemToFind, const int Start, const int End)
{

    if (End < Start) {
        return -1;
    }

    int midPoint = Start + ((End - Start) / 2);

    if (Data[midPoint] == ItemToFind)
    {
        return midPoint;
    }
    else if (Data[midPoint] > ItemToFind)
    {
        return BinarySearch(Data, ItemToFind, 0, midPoint -1);
    }
    else
    {
        return BinarySearch(Data, ItemToFind, midPoint + 1, End);
    }

}
