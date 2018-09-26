#include <vector>

#include "SortFunctions.h"
#include "HeapSort.h"

/*

Implementation of HeapSort and required supporting functions.

Note that I'm consistently using array-style (0-based) indices here,
rather than heap-style (1-based) which slightly impacts how some of the index calculations are done.

*/

void MaxHeapify(std::vector<int>& Data, int TopIndex, int HeapSize) {

    int leftIndex = (2 * TopIndex) + 1;
    int rightIndex = leftIndex + 1;

    int maxIndex = TopIndex;
    if (leftIndex < HeapSize && Data[leftIndex] > Data[maxIndex]) {
        maxIndex = leftIndex;
    }
    if (rightIndex < HeapSize && Data[rightIndex] > Data[maxIndex]) {
        maxIndex = rightIndex;
    }

    if (maxIndex != TopIndex) {
        SwapArrayElements(Data, TopIndex, maxIndex);
        MaxHeapify(Data, maxIndex, HeapSize);
    }

};

void BuildMaxHeap(std::vector<int>& Data) {
    
    int i;
    for (i = ((Data.size() -1) / 2); i >= 0; i--) {
        MaxHeapify(Data, i, Data.size());
    }

};

void HeapSort(std::vector<int>& Data) {
    
    BuildMaxHeap(Data);

    int i;
    for (i = Data.size() - 1; i > 0; i--) {
        SwapArrayElements(Data, 0, i);
        MaxHeapify(Data, 0, i);
    }

};
