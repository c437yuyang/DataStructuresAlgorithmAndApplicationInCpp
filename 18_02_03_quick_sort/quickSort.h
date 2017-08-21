// quick sort

#ifndef quickSort_
#define quickSort_

#include "indexOfMax.h"

using namespace std;

#pragma region 书上的版本


template <class T>
void quickSort(T a[], int n)
{// Sort a[0 : n - 1] using the quick sort method.
	if (n <= 1) return;
	// move largest element to right end
	int max = indexOfMax(a, n); //其实这里也可以不交换，假如第一个数是最大数，那么后面一直寻找比它大的数，就会一直在内存往后找比它大的，可能会找很久，因此限制一个寻找范围就行了，但是其实结果不影响，因为取决于rigthcursor和leftend交换
	swap(a[n - 1], a[max]);
	quickSort(a, 0, n - 1);
}

template <class T>
void quickSort(T a[], int leftEnd, int rightEnd)
{// Sort a[leftEnd:rightEnd], a[rightEnd+1] >= a[leftEnd:rightEnd].
	if (leftEnd >= rightEnd) return;

	int leftCursor = leftEnd,        // left-to-right cursor
		rightCursor = rightEnd + 1;  // right-to-left cursor
	T pivot = a[leftEnd];

	// swap elements >= pivot on left side
	// with elements <= pivot on right side
	while (true)
	{
		do
		{// find >= element on left side
			leftCursor++;
		} while (a[leftCursor] < pivot);

		do
		{// find <= element on right side
			rightCursor--;
		} while (a[rightCursor] > pivot);

		if (leftCursor >= rightCursor) break;  // swap pair not found
		swap(a[leftCursor], a[rightCursor]);
	}

	// place pivot
	a[leftEnd] = a[rightCursor];
	a[rightCursor] = pivot;

	quickSort(a, leftEnd, rightCursor - 1);   // sort left segment
	quickSort(a, rightCursor + 1, rightEnd);  // sort right segment
}



template <class T>
void quickSort_with_border_conditon(T a[], int n)
{// Sort a[0 : n - 1] using the quick sort method.
	if (n <= 1) return;
	// move largest element to right end
	//int max = indexOfMax(a, n); //其实这里也可以不交换，假如第一个数是最大数，那么后面一直寻找比它大的数，就会一直在内存往后找比它大的，可能会找很久，因此限制一个寻找范围就行了，但是其实结果不影响，因为取决于rigthcursor和leftend交换
	//swap(a[n - 1], a[max]);//这里改为限制边界条件就可以了
	quickSort_with_border_conditon(a, 0, n - 1);
}

template <class T>
void quickSort_with_border_conditon(T a[], int leftEnd, int rightEnd)
{// Sort a[leftEnd:rightEnd], a[rightEnd+1] >= a[leftEnd:rightEnd].
	if (leftEnd >= rightEnd) return;

	int leftCursor = leftEnd,        // left-to-right cursor
		rightCursor = rightEnd + 1;  // right-to-left cursor
	T pivot = a[leftEnd];

	// swap elements >= pivot on left side
	// with elements <= pivot on right side
	while (true)
	{
		do
		{// find >= element on left side
			leftCursor++;
		} while (a[leftCursor] < pivot && leftCursor < rightEnd); //限制边界

		do
		{// find <= element on right side
			rightCursor--;
		} while (a[rightCursor] > pivot && rightCursor > leftEnd);

		if (leftCursor >= rightCursor) break;  // swap pair not found
		swap(a[leftCursor], a[rightCursor]);
	}

	// place pivot
	a[leftEnd] = a[rightCursor];
	a[rightCursor] = pivot;

	quickSort_with_border_conditon(a, leftEnd, rightCursor - 1);   // sort left segment
	quickSort_with_border_conditon(a, rightCursor + 1, rightEnd);  // sort right segment
}



template <class T>
void median_of_three_quickSort(T a[], int n)
{
	if (n <= 1) return;
	// move largest element to right end
	int max = indexOfMax(a, n);
	swap(a[n - 1], a[max]);
	median_of_three_quickSort(a, 0, n - 2);
}

template <class T>
void median_of_three_quickSort(T a[], int leftEnd, int rightEnd)
{
	if (leftEnd >= rightEnd) return;
	if (rightEnd - leftEnd >= 2) 
	{
		int mid = (rightEnd + leftEnd) / 2;
		if ((a[leftEnd] <= a[mid] && a[rightEnd] >= a[mid])||
			(a[leftEnd] >= a[mid] && a[rightEnd] <= a[mid])) //mid为中值
			swap(a[mid], a[leftEnd]);
		if ((a[leftEnd] <= a[rightEnd] && a[mid] >= a[rightEnd])
			||(a[leftEnd] >= a[rightEnd] && a[mid] <= a[rightEnd]))//右边是中值
			swap(a[leftEnd], a[rightEnd]);
	}

	int leftCursor = leftEnd,        // left-to-right cursor
		rightCursor = rightEnd + 1;  // right-to-left cursor
	T pivot = a[leftEnd];

	// swap elements >= pivot on left side
	// with elements <= pivot on right side
	while (true)
	{
		do
		{// find >= element on left side
			leftCursor++;
		} while (a[leftCursor] < pivot);

		do
		{// find <= element on right side
			rightCursor--;
		} while (a[rightCursor] > pivot);

		if (leftCursor >= rightCursor) break;  // swap pair not found
		swap(a[leftCursor], a[rightCursor]);
	}

	// place pivot
	a[leftEnd] = a[rightCursor];
	a[rightCursor] = pivot;

	median_of_three_quickSort(a, leftEnd, rightCursor - 1);   // sort left segment
	median_of_three_quickSort(a, rightCursor + 1, rightEnd);  // sort right segment
}

#pragma endregion



#pragma region 算法导论的版本
template<class T>
int partition(T a[], int p, int r);
template <class T>
void quickSort_my(T a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quickSort_my(a, p, q - 1);
		quickSort_my(a, q + 1, r);
	}
}

template <class T>
int partition(T a[], int p, int r)
{
	int i = p - 1;
	for (int j = p; j != r; ++j)
	{
		if (a[j] <= a[r])
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

#pragma endregion


#pragma region 网上看到的版本，选择第一个数作为基元
template <class T>
void quickSort2(T a[], int p, int r)
{
	if (p < r)
	{
		int q = partition2(a, p, r);
		quickSort2(a, p, q - 1);
		quickSort2(a, q + 1, r);
	}

}

template<class T >
int partition2(T a[], int p, int r)
{
	T x = a[p]; //取第一个数为主元
	int left = p + 1;
	int right = r;
	int empty = p;
	bool rightmove = true;
	while (left <= right)
	{
		if (rightmove)
		{
			if (a[right] <= x)
			{
				a[empty] = a[right];
				empty = right;
				rightmove = false;
			}
			else
			{
				right--;
			}
		}
		else
		{
			if (a[left] > x)
			{
				a[empty] = a[left];
				empty = left;
				rightmove = true;
			}
			else
			{
				left++;
			}
		}
	}
	a[empty] = x;
	return empty;
}
#pragma endregion
#endif
