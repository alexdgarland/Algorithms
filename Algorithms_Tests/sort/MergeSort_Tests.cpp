#include "SortTestHelpers.h"
#include "../../Algorithms/sort/MergeSort.h"

namespace SortingAlgorithms_Tests
{

    TEST_CLASS(MergeSort_Tests)
    {

    private:

        vector<int> VectorFrom(int array[]) {
            return vector<int>(array, array + sizeof(array));
        }

    public:

        TEST_METHOD(Test_MergeSort)
        {
            MergeSorter mergeSort;
            standardSortTest(mergeSort);
        }

        TEST_METHOD(Test_MergeSortedSections)
        {
            int testArray[] = { 1, 3, 5, 2, 4, 6 };
            int expectedArray[] = { 1, 2, 3, 4, 5, 6 };

            MergeSorter::MergeSortedSections(testArray, 6, 3);

            assertSameIntVectors(VectorFrom(expectedArray), VectorFrom(testArray));
        }

    };

}