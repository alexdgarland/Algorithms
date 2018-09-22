#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <time.h>

#include "SortFunctions.h"
#include "MergeSort.h"

constexpr auto ARRAYSIZE = 10;

int* GetRandomArray(int ArraySize);
int PrintArray(int* ArrayToPrint);
int DemonstrateAlgorithm(void* ImplementationFunction, const char* AlgorithmName);

int _tmain(int argc, _TCHAR* argv[])
{
    DemonstrateAlgorithm(&InsertionSort, "Insertion Sort");
    DemonstrateAlgorithm(&SelectionSort, "Selection Sort");
    DemonstrateAlgorithm(&MergeSort, "Merge Sort");
}

int DemonstrateAlgorithm(void* ImplementationFunction, const char* AlgorithmName)
{
    int* myarray = GetRandomArray(ARRAYSIZE);
    int* (*currentSortFunction)(int*,int) = (int*(*)(int*,int))(ImplementationFunction);

    printf("\nDemonstrating sorting algorithm - %s.\n", AlgorithmName);
    printf("\nShowing random array before sorting:\n");
    PrintArray(myarray);
    currentSortFunction(myarray, ARRAYSIZE);
    printf("\nShowing array after sorting:\n");
    PrintArray(myarray);
    
    free(myarray);
    return 0;
};

int* GetRandomArray(int ArraySize)
{
    int* array = (int*)malloc(ArraySize * sizeof(int));
    int i;
    srand(time(NULL));
    for(i = 0; i < ArraySize; array[i++] = rand()) { }
    return array;
}

int PrintArray(int* ArrayToPrint)
{
    int i;
    for (i = 0; i < ARRAYSIZE; i++) { printf("%d ", ArrayToPrint[i]); }
    printf("\n");
    return 0;
}
