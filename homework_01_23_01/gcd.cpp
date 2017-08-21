#include <iostream>
#include <algorithm>
using namespace std;



int gcd(int x, int y)
{
	cout << "gcd(" << x << "," << y << ")" << endl;
	if (x < 0 || y < 0) return -1;
	if (y == 0) return x;
	else
		return gcd(y, x%y);
}

int main()
{

	cout << gcd(20, 30) << endl;

	system("pause");

}