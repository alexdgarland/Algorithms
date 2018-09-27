#include "CppUnitTest.h"
#include <boost/assign/std/vector.hpp>
#include "../../Algorithms/search/SearchFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace boost::assign;


namespace SearchAlgorithms_Tests
{

    TEST_CLASS(SearchFunctions_Tests)
    {

    public:

        TEST_METHOD(Test_LinearSearch)
        {
            vector<int> data;
            data += 1, 2, 3, 4, 5, 6, 7;
            
            Assert::AreEqual(4, LinearSearch(data, 5));
        }

        TEST_METHOD(Test_LinearSearch_ItemNotPresent)
        {
            vector<int> data;
            data += 1, 2, 3, 4, 5, 6, 7;

            Assert::AreEqual(-1, LinearSearch(data, 100));
        }

        TEST_METHOD(Test_BinarySearch_7Items)
        {
            vector<int> data;
            data += 1, 2, 3, 4, 5, 6, 7;

            Assert::AreEqual(4, BinarySearch(data, 5));
        }

        TEST_METHOD(Test_BinarySearch_1Item)
        {
            vector<int> data;
            data += 5;
            
            Assert::AreEqual(0, BinarySearch(data, 5));
        }

        TEST_METHOD(Test_BinarySearch_ItemNotPresent)
        {
            vector<int> data;
            data += 1, 2, 3, 4, 5, 6, 7;

            Assert::AreEqual(-1, BinarySearch(data, 100));
        }

    };

}
