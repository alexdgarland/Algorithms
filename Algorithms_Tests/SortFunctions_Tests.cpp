#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\SortFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingAlgorithms_Tests
{        

    TEST_CLASS(ImplementationFunctions_Tests)
    {

    private:

        void standardTest_SortAlgorithm(void* SortFunctionPtr)
        {
            int i;
            int testArray[] = { 27976, 13779, 9340, 10777, 25894, 20028, 2681, 23739, 18613, 13682 };
            int expectedArray[] = { 2681, 9340, 10777, 13682, 13779, 18613, 20028, 23739, 25894, 27976 };
            int*(*SortFunction)(int*, int) = (int*(*)(int*, int))(SortFunctionPtr);
            
            SortFunction(testArray, 10);
            
            for (i = 0; i < 10 ; i++)
            {
                Assert::AreEqual(expectedArray[i], testArray[i]);
            }
        }

    public:
    
        TEST_METHOD(Test_SwapArrayElements)
        {
            int testArray[] = { 1, 2, 3 };
            SwapArrayElements(testArray, 0, 2);
            Assert::AreEqual(testArray[0], 3);  // Swappped
            Assert::AreEqual(testArray[1], 2);  // Unchanged
            Assert::AreEqual(testArray[2], 1);  // Swapped
        }

        TEST_METHOD(Test_InsertionSort)
        {
            this->standardTest_SortAlgorithm(&InsertionSort);
        }

        TEST_METHOD(Test_SelectionSort)
        {
            this->standardTest_SortAlgorithm(&SelectionSort);
        }

        TEST_METHOD(Test_MergeSort)
        {
            this->standardTest_SortAlgorithm(&MergeSort);
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
            MergeSortedSections(testArray, 6, 3);
            int expectedArray[] = { 1, 2, 3, 4, 5, 6 };
            int i;
            for (i=0; i<6; i++)
            {
                Assert::AreEqual(expectedArray[i], testArray[i]);
            }
        }
    };
}