#pragma once

/* Helper functions */
int FindIndexOfSmallestElement(const std::vector<int> Data, const int StartIndex, const int EndIndex);
void SwapArrayElements(std::vector<int>& Data, const int Index1, const int Index2);

/* Basic sort functions */
void InsertionSort(std::vector<int>& Data);
void SelectionSort(std::vector<int>& Data);
void BubbleSort(std::vector<int>& Data);
