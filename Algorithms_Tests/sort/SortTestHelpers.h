#include "CppUnitTest.h"
#include <boost/assign/std/vector.hpp>
#include "../../Algorithms/sort/VectorSorter.h"

#pragma once

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace boost::assign;

namespace SortingAlgorithms_Tests
{

    inline void assertSameIntVectors(vector<int> expected, vector<int> actual) {

        Assert::AreEqual(expected.size(), actual.size());

        int i;
        for (i = 0; i < expected.size(); i++)
        {
            Assert::AreEqual(expected[i], actual[i]);
        }

    }

    inline void standardSortTest(VectorSorter& sort)
    {
        vector<int> testVector;
        testVector += 27976, 13779, 9340, 10777, 25894, 20028, 2681, 23739, 18613, 13682;

        vector<int> expectedVector;
        expectedVector += 2681, 9340, 10777, 13682, 13779, 18613, 20028, 23739, 25894, 27976;

        sort(testVector);

        assertSameIntVectors(expectedVector, testVector);
    }

}
