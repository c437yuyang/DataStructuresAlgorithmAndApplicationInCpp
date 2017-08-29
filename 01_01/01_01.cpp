// 01_01.cpp : 定义控制台应用程序的入口点。
//
//58 2017年笔试题
//题目：小名打王者荣耀目前战斗力为c，每天他会遇到n个对手，战斗力分别为s1,s2...sn
//当小名战斗力高于这个对手，小名的战斗力上升目前遇到的对手的战斗力和自己当前战斗力的最大公约数
//当小名的战斗力低于这个对手也会取胜，上升目前遇到的所有对手的战斗力的均值
//输出最后小名的战斗力


#include "stdafx.h"
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if (x < 0 || y < 0) return -1;
	if (y == 0) return x;
	else
		return gcd(y, x%y);
}

int lastscore(int x, int n, int s[]) 
{
	int sum = 0;
	int cur = x;
	for (int i=0;i!=n;++i)
	{
		sum += s[i];
		int avg = (double)sum / (i + 1);
		if (s[i] > cur) 
			cur += avg;
		else
		{
			cur += gcd(cur, s[i]);
		}
	}
	return cur;
}

int main()
{
	int s[] = { 2700,3500,4000 };
	int x = 3000;
	cout << lastscore(x, 3, s);

    return 0;
}

