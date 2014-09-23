#include "stdafx.h"
#pragma once

typedef int ArrayIndex;

typedef struct SubArray
{
    ArrayIndex left;
    ArrayIndex right;
    int sum;
} SubArray;

SubArray FindMaxCrossingSubarray(int A[], ArrayIndex low, ArrayIndex mid, ArrayIndex high);

int* ConvertPricesToDeltas(int* prices, int length);


