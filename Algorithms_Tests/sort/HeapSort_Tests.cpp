#include "SortTestHelpers.h"
#include "../../Algorithms/sort/HeapSort.h"

namespace SortingAlgorithms_Tests
{

    TEST_CLASS(HeapSort_Tests)
    {

        TEST_METHOD(Test_HeapSort)
        {
            HeapSorter heapSort;
            standardSortTest(heapSort);
        }

        TEST_METHOD(Test_MaxHeapifySubtree)
        {
            vector<int> testVector;
            testVector += 1, 3, 5, 2, 4, 6;
            /*
                                    1
             Act here >>>   3               5
                        2       4       6

             Sorts only the left subtree (the child nodes are leaves so already satisfy the max-heap property). Expected result:

                                    1
                            4               5
                        2       3       6
            */
            vector<int> expectedVector;
            expectedVector += 1, 4, 5, 2, 3, 6;

            HeapSorter::MaxHeapify(testVector, 1, 6);

            assertSameIntVectors(expectedVector, testVector);

        }

        TEST_METHOD(Test_MaxHeapifyFullTree)
        {
            vector<int> testVector;
            testVector += 1, 4, 5, 2, 6, 3, 0;
            /*
                                    1
                            4               5
                        2       6       3       0

            The right subtree should end up fully sorted and maintain its max-heap property.
            The left subtree does not satisfy the max-heap property, but by design the algorithm assumes it does and does not fix.

            Expected result:

                                    5
                            4               3
                        2       6       1       0

            */
            vector<int> expectedVector;
            expectedVector += 5, 4, 3, 2, 6, 1, 0;

            HeapSorter::MaxHeapify(testVector, 0, 7);

            assertSameIntVectors(expectedVector, testVector);

        }

        TEST_METHOD(Test_BuildMaxHeap)
        {
            vector<int> testVector;
            testVector += 1, 4, 5, 2, 6, 3, 0;
            /*
                                    1
                            4               5
                        2       6       3       0

            This should get fully built into a max heap. Expected result:

                                    6
                            4               5
                        2       1       3       0
            */
            vector<int> expectedVector;
            expectedVector += 6, 4, 5, 2, 1, 3, 0;

            HeapSorter::BuildMaxHeap(testVector);

            assertSameIntVectors(expectedVector, testVector);

        }

    };

}
