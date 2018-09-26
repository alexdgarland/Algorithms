#include <vector>

#pragma once

void MergeSort(std::vector<int> Data);
void InnerMergeSort(int* Data, int DataSize);
void MergeSortedSections(int* ArrayToSort, int ArraySize, int SplitPoint);
