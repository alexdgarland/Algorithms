#include "SortFunctions.h"
#include "HeapSort.h"

/*

Implementation of HeapSort and required supporting functions.

Note that I'm consistently using array-style (0-based) indices here,
rather than heap-style (1-based) which slightly impacts how some of the index calculations are done.

*/

void MaxHeapify(int* ArrayToSort, int TopIndex, int HeapSize) {

    int leftIndex = (2 * TopIndex) + 1;
    int rightIndex = leftIndex + 1;

    int maxIndex = TopIndex;
    if (leftIndex < HeapSize && ArrayToSort[leftIndex] > ArrayToSort[maxIndex]) {
        maxIndex = leftIndex;
    }
    if (rightIndex < HeapSize && ArrayToSort[rightIndex] > ArrayToSort[maxIndex]) {
        maxIndex = rightIndex;
    }

    if (maxIndex != TopIndex) {
        SwapArrayElements(ArrayToSort, TopIndex, maxIndex);
        MaxHeapify(ArrayToSort, maxIndex, HeapSize);
    }

};

void BuildMaxHeap(int* ArrayToSort, int ArraySize) {
    
    int i;
    for (i = ((ArraySize -1) / 2); i >= 0; i--) {
        MaxHeapify(ArrayToSort, i, ArraySize);
    }

};

void HeapSort(int* ArrayToSort, int ArraySize) {
    
    BuildMaxHeap(ArrayToSort, ArraySize);

    int i;
    for (i = ArraySize - 1; i > 0; i--) {
        SwapArrayElements(ArrayToSort, 0, i);
        MaxHeapify(ArrayToSort, 0, i);
    }

};
