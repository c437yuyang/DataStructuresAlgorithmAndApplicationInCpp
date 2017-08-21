// output all permutations of n elements

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

bool status[3] = { 0,0,0 };


template<class T>
void subsetGeneration(T list[], int n, bool *status)
{
	//for (int i = 0; i != n; ++i)
	//{
	//	if (!status[i]) //如果还有没有移出的元素
	//	{
	//		for (int j = 0; j = )
	//		{
	//		}

	//		break;
	//	}
	//}

	for (int j = 0; j != n; ++j)
	{
		if (!status[j]) 
		{
			cout << list[j] << " ";
			status[j] = true;
			subsetGeneration(list, n, status);
		}
			
	}
}

int main()
{
	char a[] = { 'a', 'b', 'c', 'd' };

	bool status[] = { false,false,false,false };

	subsetGeneration(a, sizeof(a) / sizeof(a[0]), status);

	return 0;
}
