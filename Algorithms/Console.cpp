#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <time.h>
#include <vector>

#include "SortFunctions.h"
#include "MergeSort.h"
#include "HeapSort.h"

constexpr auto DATA_SIZE = 10;

std::vector<int> GetRandomData();
void PrintData(std::vector<int> ArrayToPrint, const char* Message);
void DemonstrateAlgorithm(void* ImplementationFunction, const char* AlgorithmName);

std::vector<int> GetRandomData()
{
    std::vector<int> data(DATA_SIZE);
    
    srand(time(NULL));

    int i;
    for(i = 0; i < DATA_SIZE; data[i++] = rand()) { }
    
    return data;
}

void PrintData(std::vector<int> Data, const char* Description)
{
    printf("\nShowing %s:\n", Description);

    int i;
    for (i = 0; i < Data.size(); i++) {
        printf("%d ", Data[i]);
    }
    printf("\n");
}

void DemonstrateAlgorithm(void* Impl, const char* AlgorithmName)
{
    std::vector<int> array = GetRandomData();
    std::vector<int>(*currentSortFunction)(std::vector<int>, int) = (std::vector<int>(*)(std::vector<int>, int))(Impl);

    printf("\n**** Demonstrating sorting algorithm - %s ****\n", AlgorithmName);
    PrintData(array, "random array before sorting");

    currentSortFunction(array, DATA_SIZE);
    
    PrintData(array, "array after sorting");
    printf("\n");


}

int _tmain(int argc, _TCHAR* argv[])
{
    DemonstrateAlgorithm(&InsertionSort, "Insertion Sort");
    DemonstrateAlgorithm(&SelectionSort, "Selection Sort");
    DemonstrateAlgorithm(&MergeSort, "Merge Sort");
    DemonstrateAlgorithm(&HeapSort, "Heap Sort");
}
