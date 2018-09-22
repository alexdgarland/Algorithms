#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\SortFunctions.h"
#include "..\Algorithms\MergeSort.h"
#include "..\Algorithms\HeapSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingAlgorithms_Tests
{


    TEST_CLASS(SortImplementation_Tests)
    {

    private:

        void standardSortTest(void* SortFunctionPtr)
        {
            int testArray[] = { 27976, 13779, 9340, 10777, 25894, 20028, 2681, 23739, 18613, 13682 };
            int expectedArray[] = { 2681, 9340, 10777, 13682, 13779, 18613, 20028, 23739, 25894, 27976 };
            
            int*(*SortFunction)(int*, int) = (int*(*)(int*, int))(SortFunctionPtr);

            SortFunction(testArray, 10);

            int i;
            for (i = 0; i < 10; i++)
            {
                Assert::AreEqual(expectedArray[i], testArray[i]);
            }
        }

    public:

        TEST_METHOD(Test_InsertionSort)
        {
            this->standardSortTest(&InsertionSort);
        }

        TEST_METHOD(Test_SelectionSort)
        {
            this->standardSortTest(&SelectionSort);
        }

        TEST_METHOD(Test_BubbleSort)
        {
            this->standardSortTest(&BubbleSort);
        }

        TEST_METHOD(Test_MergeSort)
        {
            this->standardSortTest(&MergeSort);
        }

        TEST_METHOD(Test_HeapSort)
        {
            this->standardSortTest(&HeapSort);
        }

    };


    TEST_CLASS(SortHelperFunctionTests)
    {

    public:

        TEST_METHOD(Test_SwapArrayElements)
        {
            int testArray[] = { 1, 2, 3 };

            SwapArrayElements(testArray, 0, 2);

            Assert::AreEqual(testArray[0], 3);  // Swappped
            Assert::AreEqual(testArray[1], 2);  // Unchanged
            Assert::AreEqual(testArray[2], 1);  // Swapped
        }

        TEST_METHOD(Test_FindIndexOfSmallestElement)
        {
            int testArray[] = { 1, 4, 3, 4, 5, 1 };
            int indexOfSmallest = FindIndexOfSmallestElement(testArray, 1, 4);

            Assert::AreEqual(2, indexOfSmallest);
        }

        TEST_METHOD(Test_MergeSortedSections)
        {
            int testArray[] = { 1, 3, 5, 2, 4, 6 };
            int expectedArray[] = { 1, 2, 3, 4, 5, 6 };

            MergeSortedSections(testArray, 6, 3);

            int i;
            for (i = 0; i < 6; i++)
            {
                Assert::AreEqual(expectedArray[i], testArray[i]);
            }
        }

        TEST_METHOD(Test_MaxHeapify)
        {
            Assert::AreEqual("", "*", "This test is not implemented");
        }

        TEST_METHOD(Test_BuildMaxHeap)
        {
            Assert::AreEqual("", "*", "This test is not implemented");
        }

    };


}
