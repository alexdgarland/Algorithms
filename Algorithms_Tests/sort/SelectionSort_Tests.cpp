#include "SortTestHelpers.h"
#include "../../Algorithms/sort/SelectionSort.h"

namespace SortingAlgorithms_Tests
{

    TEST_CLASS(SelectionSort_Tests)
    {

        TEST_METHOD(Test_SelectionSort)
        {
            SelectionSorter selectionSort;
            standardSortTest(selectionSort);
        }

        TEST_METHOD(Test_FindIndexOfSmallestElement)
        {
            vector<int> testVector;
            testVector += 1, 4, 3, 4, 5;

            int indexOfSmallest = SelectionSorter::FindIndexOfSmallest(testVector, 1);

            Assert::AreEqual(2, indexOfSmallest);
        }

    };

}