#ifndef ImplementationFunctions_INCLUDED

#define ImplementationFunctions_INCLUDED

/* Main sort functions */
int* InsertionSort(int* ArrayToSort, int ArraySize);
int* SelectionSort(int* ArrayToSort, int ArraySize);
int* BubbleSort(int* ArrayToSort, int ArraySize);
int* MergeSort(int* ArrayToSort, int ArraySize);
/* Helper functions */
int FindIndexOfSmallestElement(const int* Array, const int StartIndex, const int EndIndex);
int* SwapArrayElements(int* ArrayToChange, int ElemIndex1, int ElemIndex2);
int* MergeSortedSections(int* ArrayToSort, int ArraySize, int SplitPoint);

#endif /* ImplementationFunctions_INCLUDED */