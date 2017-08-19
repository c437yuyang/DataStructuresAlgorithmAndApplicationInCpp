// compute element ranks

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

//这里的名次说的是，一个元素在序列中所有比它小的元素个数加上在它左边相等的元素个数
template<class T>
void _rank(T a[], int n, int r[])
{// Rank the n elements a[0:n-1].
 // Element ranks returned in r[0:n-1]
	for (int i = 0; i < n; i++)
		r[i] = 0;  // initialize

	 // compare all element pairs
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i]) r[i]++;
			else r[j]++;
}

//我自己写的版本,虽然复杂度都是O(n^2)但是上面更少耗时
template<class T>
void _rank_my(T a[], int n, int r[])
{// Rank the n elements a[0:n-1].
 // Element ranks returned in r[0:n-1]
	for (int i = 0; i < n; i++)
		r[i] = 0;  // initialize

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			if (i == j)continue;
			if (a[j] < a[i]) r[i]++;
			if (a[j] == a[i] && j < i) r[i]++;
		}
	}
}


template<class T>
void rearrange(T a[], int n, int r[])
{// Rearrange the elements of a into sorted order
 // using an additional array u.
	T *u = new T[n]; // create additional array

					 // move to correct place in u
	for (int i = 0; i < n; i++)
		u[r[i]] = a[i];

	// move back to a
	for (int i = 0; i < n; i++)
		a[i] = u[i];

	delete[] u;
}


template<class T>
void rearrange1(T a[], int n, int r[]) //空间复杂度O(1),不借助外部存储
{// Rearrange the elements of a into sorted order
	for (int i=0;i!=n;++i)
	{
		while (r[i]!=i)
		{
			int t = r[i];
			swap(r[i], r[t]);
			swap(a[i], a[t]);
			//不能swap(r[i],a[r[i]]);
		}
	}

}


int main()
{
	//int a[6] = { 2, 6, 4, 3, 1, 5 };
	int a[6] = { 4,3,9,3,7,4 };

	int r[6];

	// output the elements
	cout << "a[0:5] = ";
	copy(a, a + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	// determine the ranks
	_rank(a, 6, r);

	// output the ranks
	cout << "r[0:5] = ";
	copy(r, r + 6, ostream_iterator<int>(cout, " "));
	cout << endl;


	// determine the ranks 测试我自己的版本
	_rank_my(a, 6, r);

	// output the ranks
	cout << "r[0:5] = ";
	copy(r, r + 6, ostream_iterator<int>(cout, " "));
	cout << endl;


	//rearrange(a, 6, r);
	rearrange1(a, 6, r);

	// output the sorted sequence
	cout << "After the sort, a[0:5] = ";
	copy(a, a + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
