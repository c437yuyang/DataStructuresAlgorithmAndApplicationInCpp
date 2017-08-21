// bubble sort

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
#include <time.h>
using namespace std;


//template<class T>
//void bubble(T a[], int n)
//{// Bubble largest element in a[0:n-1] to right.
//   for (int i = 0; i < n - 1; i++)
//      if (a[i] > a[i+1]) swap(a[i], a[i + 1]);
//}
//
//template<class T>
//void bubbleSort(T a[], int n)
//{// Sort a[0:n - 1] using bubble sort.
//   for (int i = n; i > 1; i--)
//      bubble(a, i);
//}

template<class T>
void bubbleSort(T a[], int n)
{
	//������ð�����
	for (int i = n - 1; i >= 0; --i) //�����һ������ǰ
	{
		//for (int j = 0; j != i; ++j) //�ӵ�һ����������ǰ��������������һ����a[i]��������֮������!=i�Ǻ����õ�a[j+1],���ԶԱ���һ�ξ�֪����
		//{
		//	if (a[j] > a[j + 1])
		//		swap(a[j], a[j + 1]);
		//}

		for (int j = 1; j <= i; ++j) //��ʵ����Ҫ��֤�����߽綼�ܱ��Ƚϵ�������
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}

	}

	//����С��ð����ǰ��
	//for (int i = 0; i != n - 1; ++i)
	//{
	//	for (int j = n - 1; j != i; --j)
	//	{
	//		if (a[j] < a[j - 1])
	//			swap(a[j], a[j - 1]);
	//	}
	//}

}


template<class T>
void bubbleSortWithStopCriteria(T a[], int n)
{
	bool sorted = false;
	//������ð�����

	for (int i = n - 1; i >= 0 && !sorted; --i) //�����һ������ǰ
	{
		sorted = true;
		for (int j = 1; j <= i; ++j)
		{
			if (a[j] < a[j - 1]) 
			{
				swap(a[j], a[j - 1]);
				sorted = false; //û�з������� ˵�������Ѿ�������
			}
				
		}

	}

}




int main()
{
	//int a[10] = { 10,7,8,9,4, 2, 3, 6, 5,1 };
	int a[10] = {1,2,3,4,5,6,7,8,9,10 };

	// output the elements
	cout << "a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;

	// sort
	//bubbleSort(a, 10);
	bubbleSortWithStopCriteria(a, 10);

	// output the sorted sequence
	cout << "After the sort, a[0:9] = ";
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;



	clock(); //

	return 0;
}
