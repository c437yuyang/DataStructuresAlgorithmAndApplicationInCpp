// dynamic programming recursive knapsack

#include <iostream>
#include <math.h>

using namespace std;

template <class T>
inline T max(const T& lhs, const T& rhs) { return lhs < rhs ? rhs : lhs; }

// global variables
int *profit; //profit和weight的下标都是从1开始
int *weight;
int numberOfObjects;

int f(int i, int theCapacity)
{// Return f(i,theCapacity).
   if (i == numberOfObjects)
      return (theCapacity < weight[numberOfObjects])
              ? 0 : profit[numberOfObjects];
   if (theCapacity < weight[i]) //这里包含了theCapacity=0的情况，并且可以兼容如果有一个物品的weight为0，那么必要
      return f(i + 1, theCapacity); 
   return max(f(i + 1, theCapacity),
               f(i + 1, theCapacity - weight[i]) + profit[i]);
}


//int f(int i, int capacity) 
//{
//	if (i == numberOfObjects) { return weight[i] <= capacity ? profit[i] : 0; }
//	if (weight[i] > capacity) return f(i + 1, capacity);
//
//	return max(f(i + 1, capacity), f(i + 1, capacity - weight[i]) + profit[i]);
//}


void main(void)
{
   cout << "Enter number of objects and knapsack capacity" << endl;
   int knapsackCapacity;
   cin >> numberOfObjects >> knapsackCapacity;
   profit = new int [numberOfObjects + 1];
   weight = new int [numberOfObjects + 1];

   for (int i = 1; i <= numberOfObjects; i++)
   {
      cout << "Enter profit and weight of object " << i << endl;
      cin >> profit[i] >> weight[i];
   }

   cout << "Optimal value is " << f(1, knapsackCapacity) << endl;
}
