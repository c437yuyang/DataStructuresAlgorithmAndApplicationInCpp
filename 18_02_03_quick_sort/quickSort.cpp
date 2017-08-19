// test quick sort

#include <iostream>
#include <algorithm> // has copy
#include "quickSort.h"
#include <iterator>
using namespace std;


int main()
{
   //int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};
   int a[10] = { 10,7,8,9,441, 2, 3, 6, 5,1 };
   //int a[9] = {25,84,21,47,15,27,68,35,20};

   // output the elements
   cout << "a[0:9] = ";
   //copy(a, a + 10, ostream_iterator<int>(cout, " "));
   copy(a, a + 10, ostream_iterator<int>(cout, " "));
   cout << endl;

   // sort
   //quickSort(a,10);
   //quickSort_my(a, 0, 9);
   quickSort2(a, 0, 9);
   // output the sorted sequence
   cout << "After the sort, a[0:9] = ";
   copy(a, a+10, ostream_iterator<int>(cout, " "));
   cout << endl;
   return 0;
}
