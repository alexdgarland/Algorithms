#include "CppUnitTest.h"
#include <vector>
#include <boost/assign/std/vector.hpp>

#include "..\Algorithms\SortFunctions.h"
#include "..\Algorithms\BubbleSort.h"
#include "..\Algorithms\MergeSort.h"
#include "..\Algorithms\HeapSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace boost::assign;

namespace SortingAlgorithms_Tests
{

    std::vector<int> VectorFrom(int array[]) {
        return std::vector<int>(array, array + sizeof(array));
    }

    void assertSameIntVectors(std::vector<int> expected, std::vector<int> actual) {

        Assert::AreEqual(expected.size(), actual.size());

        int i;
        for (i = 0; i < expected.size(); i++)
        {
            Assert::AreEqual(expected[i], actual[i]);
        }

    }

    TEST_CLASS(SortImplementation_Tests)
    {

    private:

        void standardSortTest(VectorSorter& sort)
        {
            std::vector<int> testVector;
            testVector += 27976, 13779, 9340, 10777, 25894, 20028, 2681, 23739, 18613, 13682;
            
            std::vector<int> expectedVector;
            expectedVector += 2681, 9340, 10777, 13682, 13779, 18613, 20028, 23739, 25894, 27976;
            
            sort(testVector);

            assertSameIntVectors(expectedVector, testVector);
        }

    public:

        TEST_METHOD(Test_InsertionSort)
        {
            //this->standardSortTest(&InsertionSort);
        }

        TEST_METHOD(Test_SelectionSort)
        {
            //this->standardSortTest(&SelectionSort);
        }

        TEST_METHOD(Test_BubbleSort)
        {
			BubbleSorter bubbleSort;
            this->standardSortTest(bubbleSort);
        }

        TEST_METHOD(Test_MergeSort)
        {
            //this->standardSortTest(&MergeSort);
        }

        TEST_METHOD(Test_HeapSort)
        {
            //this->standardSortTest(&HeapSort);
        }

    };


    TEST_CLASS(SortHelperFunctionTests)
    {

    public:

        TEST_METHOD(Test_SwapArrayElements)
        {
            std::vector<int> testVector;
            testVector += 1, 2, 3;

            SwapArrayElements(testVector, 0, 2);
            
            Assert::AreEqual(3, testVector[0]);  // Swappped
            Assert::AreEqual(2, testVector[1]);  // Unchanged
            Assert::AreEqual(1, testVector[2]);  // Swapped
        }

        TEST_METHOD(Test_FindIndexOfSmallestElement)
        {
            std::vector<int> testVector;
            testVector += 1, 4, 3, 4, 5, 1;

            int indexOfSmallest = FindIndexOfSmallestElement(testVector, 1, 4);

            Assert::AreEqual(2, indexOfSmallest);
        }

        TEST_METHOD(Test_MergeSortedSections)
        {
            int testArray[] = { 1, 3, 5, 2, 4, 6 };
            int expectedArray[] = { 1, 2, 3, 4, 5, 6 };

            MergeSortedSections(testArray, 6, 3);

            assertSameIntVectors(VectorFrom(expectedArray), VectorFrom(testArray));
        }

        TEST_METHOD(Test_MaxHeapifySubtree)
        {
            std::vector<int> testVector;
            testVector += 1, 3, 5, 2, 4, 6;
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
            std::vector<int> expectedVector;
            expectedVector += 1, 4, 5, 2, 3, 6;

            MaxHeapify(testVector, 1, 6);
            
            assertSameIntVectors(expectedVector, testVector);
        
        }

        TEST_METHOD(Test_MaxHeapifyFullTree)
        {
            std::vector<int> testVector;
            testVector += 1, 4, 5, 2, 6, 3, 0;
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
            std::vector<int> expectedVector;
            expectedVector += 5, 4, 3, 2, 6, 1, 0;
            
            MaxHeapify(testVector, 0, 7);

            assertSameIntVectors(expectedVector, testVector);
        
        }

        TEST_METHOD(Test_BuildMaxHeap)
        {
            std::vector<int> testVector;
            testVector += 1, 4, 5, 2, 6, 3, 0;
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
            std::vector<int> expectedVector;
            expectedVector += 6, 4, 5, 2, 1, 3, 0;

            BuildMaxHeap(testVector);

            assertSameIntVectors(expectedVector, testVector);

        }

    };


}
