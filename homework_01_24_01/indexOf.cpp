#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
int indexOf(const T a[], const T& val,int endIdx) 
{
	if (a[endIdx] == val) return endIdx;
	else
	{
		if (endIdx == 0) return -1;
		return indexOf(a,val, endIdx - 1);
	}
}

int main()
{

	int a[] = { 20,30,40,10 };

	cout << indexOf(a,20,3) << endl;
	cout << indexOf(a, 200, 3) << endl;
	cout << indexOf(a, 40, 3) << endl;

	system("pause");

}