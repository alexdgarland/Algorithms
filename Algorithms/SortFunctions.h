#include "stdafx.h"

#pragma once

/* Main sort functions */
int* InsertionSort(int* ArrayToSort, int ArraySize);
int* SelectionSort(int* ArrayToSort, int ArraySize);
int* BubbleSort(int* ArrayToSort, int ArraySize);

int* HeapSort(int* ArrayToSort, int ArraySize);
/* Helper functions */
int FindIndexOfSmallestElement(const int* Array, const int StartIndex, const int EndIndex);
int* SwapArrayElements(int* ArrayToChange, int ElemIndex1, int ElemIndex2);

// For heapsort
void MaxHeapify(int* ArrayToSort, int Index);
void BuildMaxHeap(int* ArrayToSort);
