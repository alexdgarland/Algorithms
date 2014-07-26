#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\SearchFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithms_Tests
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

        TEST_METHOD(Test_BinarySearch)
		{
            int arrayToSearch[] = { 1, 2, 3, 4, 5, 6, 7 };
            int searchResultIndex = BinarySearch(arrayToSearch, 7, 5);
			Assert::AreEqual(4, searchResultIndex);
		}

	};
}