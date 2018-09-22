#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\MaximumSubarray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithms_Tests
{
    TEST_CLASS(MaximumSubarray_Tests)
    {
    public:
        
        TEST_METHOD(Test_FindMaxCrossingSubarray)
        {
            int arrayToSearch[] = { 10, 12, -15, -15, 5, 6, 7, -1, -1, -1, -1 };
            SubArray result = FindMaxCrossingSubarray(arrayToSearch, 0, 5, 10);

            Assert::AreEqual(4, result.left);
            Assert::AreEqual(6, result.right);
            Assert::AreEqual(18, result.sum);
        }

        TEST_METHOD(Test_ConvertPricesToDeltas)
        {
            /* Example from Cormen et al */
            int prices[] = { 100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97 };
            int expectedDeltas[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };

            int* resultDeltas = ConvertPricesToDeltas(prices, 17);

            for(int i = 0; i < 16; i++)
            {
                Assert::AreEqual(expectedDeltas[i], resultDeltas[i]);
            }
        }

    };

}
