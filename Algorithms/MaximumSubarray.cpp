#include "stdafx.h"
#include "MaximumSubarray.h"
#include <cstdlib>

SubArray FindMaxCrossingSubarray(int A[], ArrayIndex low, ArrayIndex mid, ArrayIndex high)
{
    int sumTracker, i, j, maxLeft, maxRight;

    int leftSum = 0;
    bool leftSumIntialised = false;
    sumTracker = 0;

    for (i = mid; i >= low; i--)
    {
        sumTracker += A[i];
        if (sumTracker >= leftSum || !leftSumIntialised)
        {
            leftSumIntialised = true;
            leftSum = sumTracker;
            maxLeft = i;
        }
    }

    int rightSum = 0;
    bool rightSumInitialised = false;
    sumTracker = 0;

    for (j = mid + 1; j <= high; j++)
    {
        sumTracker+= A[j];
        if (sumTracker > rightSum || !rightSumInitialised)
        {
            rightSumInitialised = true;
            rightSum = sumTracker;
            maxRight = j;
        }
    }

    SubArray result = { maxLeft, maxRight, leftSum + rightSum };
    return result;
}

int* ConvertPricesToDeltas(int* prices, int length)
{
    int* deltas = (int*)malloc(sizeof(int) * (length-1));
    for(int i = 0; i < (length-1); i++)
    {
        deltas[i] = prices[i+1] - prices[i];
    }
    return deltas;
}
