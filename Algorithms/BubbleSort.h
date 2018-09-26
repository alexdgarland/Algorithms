#include <vector>

#pragma once


class VectorSorter {

public:
	virtual void operator()(std::vector<int>& Data) = 0;

};


class BubbleSorter : public VectorSorter {

public:

	void operator()(std::vector<int>& Data) {

		int i, j;

		for (i = 0; i < (Data.size() - 1); i++)
		{
			for (j = (Data.size() - 1); j > i; j--)
			{
				if (Data[j] < Data[j - 1])
				{
					std::swap(Data[j], Data[j - 1]);
				}
			}
		}

	}

};
