// 08_05_02_towerOfHanoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void towerOfHanoi(int n, int x, int y, int z) 
{
	if (n > 0) 
	{
		towerOfHanoi(n - 1, x, z, y);
		cout << "from " << x << " to " << y << endl;
		towerOfHanoi(n - 1, z, y, x);
	}
}

int main()
{

	towerOfHanoi(3, 1, 2, 3);

    return 0;
}

