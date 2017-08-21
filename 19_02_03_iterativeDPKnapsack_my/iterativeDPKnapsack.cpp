// iterative dynamic programming knapsack

#include <iostream>
#include <iterator>
#include <math.h>
//#include "make2dArrayNoCatch.h"
template <class T>
inline T min(const T& lhs, const T& rhs) { return lhs < rhs ? lhs : rhs; }
template <class T>
inline T max(const T& lhs, const T& rhs) { return lhs < rhs ? rhs : lhs; }
using namespace std;
int& at(int *p, int m, int n);

void knapsack(int *profit, int *weight, int numberOfObjects,
	int knapsackCapacity, int *f)
{// Iterative method to solve dynamic programming recurrence.
 // Computes f[1][knapsackCapacity] and f[i][y],
 // 2 <= i <= numberOfObjects, 0 <= y <= knapsackCapacity.
 // profit[1:numberOfObjects] gives object profits.
 // weight[1:numberOfObjects] gives object weights.

	//���ֽⷨ�Ǵ����һ������ʼ������ǰ�㣬Ҳ�ǿ��Եģ����������ĸ�����ʵû��Ӱ��

   // initialize f[numberOfObjects][]
   //�����ϵ�������˵������f[5][3-0] = 0;f[numberofobjects][]�������һ������f����
   //��Ϊ��ʱcapacity=0��3�������һ������weight>capacity������һ��Ϊ0
	int yMax = min(weight[numberOfObjects] - 1, knapsackCapacity);
	for (int y = 0; y <= yMax; y++)
		at(f, numberOfObjects, y) = 0;
	//����������ʱ�򣬾�ȡprofit��Ӧֵ
	for (int y = weight[numberOfObjects]; y <= knapsackCapacity; y++)
		at(f, numberOfObjects, y) = profit[numberOfObjects];

	// compute f[i][y], 1 < i < numberOfObjects
	for (int i = numberOfObjects - 1; i > 1; i--)
	{
		yMax = min(weight[i] - 1, knapsackCapacity);
		for (int y = 0; y <= yMax; y++)
			at(f, i, y) = at(f, i + 1, y);//��������������ǰһ������ֵ
		for (int y = weight[i]; y <= knapsackCapacity; y++)
			at(f, i, y) = max(at(f, i + 1, y), at(f, i + 1, y - weight[i]) + profit[i]);//������������¾���ǰһ�����ӵ�ǰ���͵�ǰ����ȡ�����ֵ
	}

	// compute f[1][knapsackCapacity]
	at(f, 1, knapsackCapacity) = at(f, 2, knapsackCapacity);
	if (knapsackCapacity >= weight[1])
		at(f, 1, knapsackCapacity) = max(at(f, 1, knapsackCapacity),
			at(f, 2, knapsackCapacity - weight[1]) + profit[1]);
}

void traceback(int *f, int *weight, int numberOfObjects,
	int knapsackCapacity, int *x)
{// Compute solution vector x.
	for (int i = 1; i < numberOfObjects; i++)
		if (at(f, i, knapsackCapacity) == at(f, i + 1, knapsackCapacity))
			// do not include object i
			x[i] = 0;
		else
		{// include object i
			x[i] = 1;
			knapsackCapacity -= weight[i];
		}
		x[numberOfObjects] = (at(f,numberOfObjects,knapsackCapacity) > 0)
		? 1 : 0;
}

int& at(int *p, int m, int n)
{
	return p[m*11 + n];
}

void main(void)
{
	cout << "Enter number of objects and knapsack capacity" << endl;
	int numberOfObjects, knapsackCapacity;
	cin >> numberOfObjects >> knapsackCapacity;
	int* profit = new int[numberOfObjects + 1];
	int* weight = new int[numberOfObjects + 1];

	for (int i = 1; i <= numberOfObjects; i++)
	{
		cout << "Enter profit and weight of object " << i << endl;
		cin >> profit[i] >> weight[i];
	}

	const int m = numberOfObjects + 1;
	const int n = knapsackCapacity + 1;
	int *f = new int[m*n]();
	//make2dArray(f, numberOfObjects + 1, knapsackCapacity + 1);


	knapsack(profit, weight, numberOfObjects, knapsackCapacity, f);

	cout << "Optimal value is " << at(f,1,knapsackCapacity) << endl;
	cout << "Rest of table is" << endl;
	for (int i = 1; i <= numberOfObjects; i++)
	{
		copy(f + i*n, f+i*n + knapsackCapacity + 1, ostream_iterator<int>(cout, "  "));
		cout << endl;
	}

	int *x = new int[numberOfObjects + 1];
	traceback(f, weight, numberOfObjects, knapsackCapacity, x);

	cout << endl;
	copy(x + 1, x + numberOfObjects + 1, ostream_iterator<int>(cout, "  "));
	cout << endl;
}
