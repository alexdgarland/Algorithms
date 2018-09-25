#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <time.h>
#include <vector>

#include "SortFunctions.h"
#include "MergeSort.h"
#include "HeapSort.h"

constexpr auto ARRAYSIZE = 10;

int* GetRandomArray(int ArraySize);
void PrintArray(int* ArrayToPrint, const char* Message);
void DemonstrateAlgorithm(void* ImplementationFunction, const char* AlgorithmName);

int* GetRandomArray(int ArraySize)
{
    int* array = (int*)malloc(ArraySize * sizeof(int));
    int i;
    srand(time(NULL));
    for(i = 0; i < ArraySize; array[i++] = rand()) { }
    return array;
}

void PrintArray(int* ArrayToPrint, const char* Description)
{
    printf("\nShowing %s:\n", Description);

    int i;
    for (i = 0; i < ARRAYSIZE; i++) {
        printf("%d ", ArrayToPrint[i]);
    }
    printf("\n");
}

void DemonstrateAlgorithm(void* ImplementationFunction, const char* AlgorithmName)
{
    int* array = GetRandomArray(ARRAYSIZE);
    int* (*currentSortFunction)(int*, int) = (int*(*)(int*, int))(ImplementationFunction);

    printf("\n**** Demonstrating sorting algorithm - %s ****\n", AlgorithmName);
    PrintArray(array, "random array before sorting");
    currentSortFunction(array, ARRAYSIZE);
    PrintArray(array, "array after sorting");
    printf("\n");

    free(array);
}

int _tmain(int argc, _TCHAR* argv[])
{
    DemonstrateAlgorithm(&InsertionSort, "Insertion Sort");
    DemonstrateAlgorithm(&SelectionSort, "Selection Sort");
    DemonstrateAlgorithm(&MergeSort, "Merge Sort");
    DemonstrateAlgorithm(&HeapSort, "Heap Sort");
}
