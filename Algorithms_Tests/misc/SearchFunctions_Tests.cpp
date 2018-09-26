#include "CppUnitTest.h"
#include "../../Algorithms/misc/SearchFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchAlgorithms_Tests
{

    TEST_CLASS(SearchFunctions_Tests)
    {

    public:

        TEST_METHOD(Test_LinearSearch)
        {
            int arrayToSearch[] = { 1, 2, 3, 4, 5, 6, 7 };
            int searchResultIndex = LinearSearch(arrayToSearch, 7, 5);
            Assert::AreEqual(4, searchResultIndex);
        }

        TEST_METHOD(Test_LinearSearch_ItemNotPresent)
        {
            int arrayToSearch[] = { 1, 2, 3, 4, 5, 6, 7 };
            int searchResultIndex = LinearSearch(arrayToSearch, 7, 100);
            Assert::AreEqual(-1, searchResultIndex);
        }

        TEST_METHOD(Test_BinarySearch_7Items)
        {
            int arrayToSearch[] = { 1, 2, 3, 4, 5, 6, 7 };
            int searchResultIndex = BinarySearch(arrayToSearch, 7, 5);
            Assert::AreEqual(4, searchResultIndex);
        }

        TEST_METHOD(Test_BinarySearch_1Item)
        {
            int arrayToSearch[] = { 5 };
            int searchResultIndex = BinarySearch(arrayToSearch, 1, 5);
            Assert::AreEqual(0, searchResultIndex);
        }

        TEST_METHOD(Test_BinarySearch_ItemNotPresent)
        {
            int arrayToSearch[] = { 1, 2, 3, 4, 5, 6, 7 };
            int searchResultIndex = BinarySearch(arrayToSearch, 7, 100);
            Assert::AreEqual(-1, searchResultIndex);
        }

    };

}
