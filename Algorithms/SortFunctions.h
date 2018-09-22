#pragma once

/* Helper functions */
int FindIndexOfSmallestElement(const int* Array, const int StartIndex, const int EndIndex);
int* SwapArrayElements(int* ArrayToChange, int ElemIndex1, int ElemIndex2);

/* Basic sort functions */
int* InsertionSort(int* ArrayToSort, int ArraySize);
int* SelectionSort(int* ArrayToSort, int ArraySize);
int* BubbleSort(int* ArrayToSort, int ArraySize);
