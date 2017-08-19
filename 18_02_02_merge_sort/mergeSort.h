
// iterative merge sort 


#ifndef mergeSort_
#define mergeSort_

using namespace std;

#pragma region 书上的版本
template <class T>
void mergeSort(T a[], int n)
{// Sort a[0 : n - 1] using the merge sort method.
	T *b = new T[n];
	int segmentSize = 1;
	while (segmentSize < n)
	{
		mergePass(a, b, n, segmentSize); // merge from a to b
		segmentSize += segmentSize;
		mergePass(b, a, n, segmentSize); // merge from b to a
		segmentSize += segmentSize;
	}
}

template <class T>
void mergePass(T x[], T y[], int n, int segmentSize)
{// Merge adjacent segments from x to y.
	int i = 0;   // start of the next segment
	while (i <= n - 2 * segmentSize)
	{// merge two adjacent segments from x to y
		merge(x, y, i, i + segmentSize - 1, i + 2 * segmentSize - 1);
		i = i + 2 * segmentSize;
	}

	// fewer than 2 full segments remain
	if (i + segmentSize < n)
		// 2 segments remain
		merge(x, y, i, i + segmentSize - 1, n - 1);
	else
		// 1 segment remains, copy to y
		for (int j = i; j < n; j++)
			y[j] = x[j];
}

template <class T>
void merge(T c[], T d[], int startOfFirst, int endOfFirst,
	int endOfSecond)
{// Merge two adjacent segments from c to d.
	int first = startOfFirst,       // cursor for first segment
		second = endOfFirst + 1,    // cursor for second
		result = startOfFirst;      // cursor for result

	// merge until one segment is done
	while ((first <= endOfFirst) && (second <= endOfSecond))
		if (c[first] <= c[second])
			d[result++] = c[first++];
		else
			d[result++] = c[second++];

	// take care of leftovers
	if (first > endOfFirst)
		for (int q = second; q <= endOfSecond; q++)
			d[result++] = c[q];
	else
		for (int q = first; q <= endOfFirst; q++)
			d[result++] = c[q];
}
#pragma endregion


#pragma region 我自己的版本
void merge_my(int *arr, int p, int  q, int  r);
void mergeSort_my(int *arr, int p, int r)
{
	if (p < r) //终止的时候是只有一个数的情况,p=q
	{
		int q = (p + r) / 2;
		mergeSort_my(arr, p, q);
		mergeSort_my(arr, q + 1, r);
		merge_my(arr, p, q, r);
	}
}

void merge_my(int *arr, int p, int  q, int  r)
{
	int n1 = q - p + 1;
	int n2 = r - q; // r-(q+1)+1

	int *L = new int[n1 + 1]();
	int *R = new int[n2 + 1]();

	//左半部分的数组赋值给L
	for (int i = 0; i != n1; ++i)
		L[i] = arr[p + i];

	//右半部分的数组赋值给R
	for (int i = 0; i != n2; ++i)
		R[i] = arr[q + 1 + i];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	for (int k = p, i = 0, j = 0; k <= r; ++k) //这里要是小于等于，相当于进行交换的时候必须是从左到右的所有都要进行交换才行
	{
		if (L[i] < R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}

	delete[] L;
	delete[] R;
}


#pragma endregion



#endif
