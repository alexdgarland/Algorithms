#include "SortTestHelpers.h"
#include "../../Algorithms/sort/BubbleSort.h"
#include "../../Algorithms/sort/InsertionSort.h"

namespace SortingAlgorithms_Tests
{

    TEST_CLASS(Simple_Sort_Tests)
    {

        TEST_METHOD(Test_InsertionSort)
        {
            InsertionSorter insertionSort;
            standardSortTest(insertionSort);
        }

        TEST_METHOD(Test_BubbleSort)
        {
			BubbleSorter bubbleSort;
            standardSortTest(bubbleSort);
        }

    };

}
