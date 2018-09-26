#include <string>
#include <tchar.h>
#include <time.h>
#include <iostream>

#include "sort/BubbleSort.h"
#include "sort/InsertionSort.h"
#include "sort/SelectionSort.h"
#include "sort/MergeSort.h"
#include "sort/HeapSort.h"

using namespace std;

vector<int> GetRandomData(int Size);
void PrintData(vector<int> ArrayToPrint, const string Message);
void Demonstrate(VectorSorter& Sort);

vector<int> GetRandomData(int Size)
{
    vector<int> data(Size);
    srand(time(NULL));
    int i;
    for (i = 0; i < Size; data[i++] = rand()) {}
    return data;
}

void PrintData(vector<int> Data, const string Description)
{
    cout << "\nShowing array " << Description << " sorting:\n";
    int i;
    for (i = 0; i < Data.size(); i++) {
        cout << Data[i] << " ";
    }
    cout << "\n";
}

void Demonstrate(VectorSorter& Sort)
{
    vector<int> array = GetRandomData(10);

    cout << "\n\n**** Demonstrating sorting algorithm - " << Sort.AlgorithmName() << " ****\n";

    PrintData(array, "before");

    Sort(array);

    PrintData(array, "after");
}

int _tmain(int argc, _TCHAR* argv[])
{

    BubbleSorter bubbleSort;
    Demonstrate(bubbleSort);

    InsertionSorter insertionSort;
    Demonstrate(insertionSort);

    SelectionSorter selectionSort;
    Demonstrate(selectionSort);

    MergeSorter mergeSort;
    Demonstrate(mergeSort);

    HeapSorter heapSort;
    Demonstrate(heapSort);

}
