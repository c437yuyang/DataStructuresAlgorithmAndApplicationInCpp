// test quick sort

#include <iostream>
#include <algorithm> // has copy
#include "quickSort.h"
#include <iterator>
#include <windows.h>
using namespace std;



int main()
{
   //int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};
   //int a[10] = { 10,7,8,9,441, 2, 3, 6, 5,1 };
   //int a[9] = {25,84,21,47,15,27,68,35,20};
   int a[10] = { 1001,7,8,9,441, 2, 3, 6, 5,1 };

   // output the elements
   cout << "a[0:9] = ";
   //copy(a, a + 10, ostream_iterator<int>(cout, " "));
   copy(a, a + 10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // sort
   quickSort(a,10);
   //quickSort_my(a, 0, 9);
   //quickSort2(a, 0, 9);
   // output the sorted sequence
   cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));

   cout << endl;
#pragma region 测试三只取中法和普通快排对于已经排好序的数组的速度
   const int n = 100;
   int arr[n];
   for (int i = 0; i != n; ++i)
	   arr[i] = i + 1;
   const int nTestTime = 1000;

   DWORD start = GetTickCount();

   for (int i=0;i!=nTestTime;++i)
   {
	   int arr1[n];
	   memcpy(arr1, arr, sizeof(arr));
	   median_of_three_quickSort(arr1, n);
	   if (memcmp(arr1, arr, sizeof(arr))) 
	   {
		   cout << "2333" << endl;
		   break;
	   }
   }
   DWORD end = GetTickCount();
   cout << (start - end) << endl;

   start = GetTickCount();

   for (int i = 0; i != nTestTime; ++i)
   {
	   int arr1[n];
	   memcpy(arr1, arr, sizeof(arr));
	   quickSort(arr1, n);
	   if (memcmp(arr1, arr, sizeof(arr)))
	   {
		   cout << "2333" << endl;
		   break;
	   }
   }
   end = GetTickCount();
   cout << start - end << endl;

   start = GetTickCount();

   for (int i = 0; i != nTestTime; ++i)
   {
	   int arr1[n];
	   memcpy(arr1, arr, sizeof(arr));
	   quickSort_my(arr1, 0,n-1);
	   if (memcmp(arr1, arr, sizeof(arr)))
	   {
		   cout << "2333" << endl;
		   break;
	   }
   }
   end = GetTickCount();
   cout << start - end << endl;


   start = GetTickCount();

   for (int i = 0; i != nTestTime; ++i)
   {
	   int arr1[n];
	   memcpy(arr1, arr, sizeof(arr));
	   quickSort2(arr1, 0,n-1);
	   if (memcmp(arr1, arr, sizeof(arr)))
	   {
		   cout << "2333" << endl;
		   break;
	   }
   }
   end = GetTickCount();
   cout << start - end << endl;


   start = GetTickCount();

   for (int i = 0; i != nTestTime; ++i)
   {
	   int arr1[n];
	   memcpy(arr1, arr, sizeof(arr));
	   quickSort_with_border_conditon(arr1, n);
	   if (memcmp(arr1, arr, sizeof(arr)))
	   {
		   cout << "2333" << endl;
		   break;
	   }
   }
   end = GetTickCount();
   cout << start - end << endl;

#pragma endregion

   //可以看到四种方法速度都差不多。。。。


   cout << endl;
   return 0;
}
