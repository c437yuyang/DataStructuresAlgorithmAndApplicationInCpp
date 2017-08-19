#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

template <class T>
void insertionSort(T a[], int n)
{
	for (int i=1;i!=n;++i)
	{

	}
}

#pragma region Version1
//在一个有序数组中插入指定值
template<class T>
void insert(T a[], int n, const T& x)
{// Insert x into the sorted array a[0:n-1].
	int i;
	for (i = n - 1; i >= 0 && x < a[i]; i--)
		a[i + 1] = a[i];
	a[i + 1] = x;
}

template<class T>
void insertionSort(T a[], int n)
{// Sort a[0:n-1] using the insertion sort method.
	for (int i = 1; i < n; i++)
	{
		T t = a[i];
		insert(a, i, t);
	}
}
#pragma endregion


#pragma region Version2
template<class T>
void insertionSortWithInlineInsert(T a[], int n)
{// Sort a[0:n-1] using the insertion sort method.
	for (int i = 1; i < n; i++)
	{// insert a[i] into a[0:i-1]
		T t = a[i];
		int j;
		for (j = i - 1; j >= 0 && t < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}
#pragma endregion



int main()
{
	int a[10] = { 3, 2, 4, 1, 6, 9, 8, 7, 5, 0 };

	// output the elements
	cout << "a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;

	// sort
	insertionSort(a, 10);

	// output the sorted sequence
	cout << "After the sort, a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}