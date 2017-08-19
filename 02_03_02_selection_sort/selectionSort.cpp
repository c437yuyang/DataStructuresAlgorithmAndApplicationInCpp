// selection sort

#include <iostream>
#include <algorithm> // has copy
#include "indexOfMax.h"
#include <iterator>
using namespace std;

template<class T>
void selectionSort(T a[], int n)
{// Sort the n elements a[0:n-1].
	for (int size = n; size > 1; size--)
	{
		int j = indexOfMax(a, size);
		swap(a[j], a[size - 1]);
	}
}

template<class T>
void selectionSortWithStopCriteria(T a[], int n)
{// Sort the n elements a[0:n-1].
	bool sorted = false;
	for (int size = n; !sorted && size > 1; size--)
	{
		int idxOfMax = 0;
		sorted = true;
		for (int j = 0; j != size; ++j)
		{
			if (a[idxOfMax] <= a[j]) idxOfMax = j;
			else sorted = false;
		}

		swap(a[idxOfMax], a[size - 1]);
	}
}

int main()
{
	int a[10] = { 3, 2, 4, 1, 6, 9, 8, 7, 5, 0 };

	// output the elements
	cout << "a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;

	// sort
	selectionSortWithStopCriteria(a, 10);

	// output the sorted sequence
	cout << "After the sort, a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
