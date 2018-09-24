#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\SortFunctions.h"
#include "..\Algorithms\MergeSort.h"
#include "..\Algorithms\HeapSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingAlgorithms_Tests
{

    void assertSameIntArrays(int* expected, int* actual, int ArraySize) {

        int i;
        for (i = 0; i < ArraySize; i++)
        {
            Assert::AreEqual(expected[i], actual[i]);
        }

    }

    TEST_CLASS(SortImplementation_Tests)
    {

    private:

        void standardSortTest(void* SortFunctionPtr)
        {
            int testArray[] = { 27976, 13779, 9340, 10777, 25894, 20028, 2681, 23739, 18613, 13682 };
            int expectedArray[] = { 2681, 9340, 10777, 13682, 13779, 18613, 20028, 23739, 25894, 27976 };
            
            int*(*SortFunction)(int*, int) = (int*(*)(int*, int))(SortFunctionPtr);

            SortFunction(testArray, 10);

            assertSameIntArrays(expectedArray, testArray, 10);
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

            assertSameIntArrays(expectedArray, testArray, 6);
        }

        TEST_METHOD(Test_MaxHeapifySubtree)
        {
            int testArray[] = { 1, 3, 5, 2, 4, 6 };
            /*
                                    1
             Act here >>>   3               5
                        2       4       6

             
             Sorts only the left subtree (the child nodes are leaves so already satisfy the max-heap property).

             Expected result:

                                    1
                            4               5
                        2       3       6
            */
            int expectedArray[] = { 1, 4, 5, 2, 3, 6 };

            MaxHeapify(testArray, 1, 6);
            
            assertSameIntArrays(expectedArray, testArray, 6);
        
        }

        TEST_METHOD(Test_MaxHeapifyFullTree)
        {
            int testArray[] = { 1, 4, 5, 2, 6, 3, 0};
            /*
                                    1
                            4               5
                        2       6       3       0


            The right subtree should end up fully sorted and maintain its max-heap property.
            The left subtree does not satisfy the max-heap property,
            but by design the algorithm assumes it does and does not fix.

            Expected result:

                                    5
                            4               3
                        2       6       1       0

            */
            int expectedArray[] = { 5, 4, 3, 2, 6, 1, 0 };

            MaxHeapify(testArray, 0, 7);

            assertSameIntArrays(expectedArray, testArray, 7);
        
        }

        TEST_METHOD(Test_BuildMaxHeap)
        {
            int testArray[] = { 1, 4, 5, 2, 6, 3, 0 };
            /*
                                    1
                            4               5
                        2       6       3       0


            This should get fully built into a max heap.

            Expected result:

                                    6
                            4               5
                        2       1       3       0

            */
            int expectedArray[] = { 6, 4, 5, 2, 1, 3, 0 };

            BuildMaxHeap(testArray, 7);

            assertSameIntArrays(expectedArray, testArray, 7);

        }

    };


}
