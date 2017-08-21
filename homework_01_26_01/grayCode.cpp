// output all permutations of n elements

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

bool status[3] = { 0,0,0 };


void grayCode(int n)
{
	if (n == 1)
		cout << n;
	else 
	{
		grayCode(n - 1);
		cout << n;
		grayCode(n - 1);
	}
}

int main()
{

	grayCode(3);
	return 0;
}
