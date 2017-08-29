// 01_01.cpp : �������̨Ӧ�ó������ڵ㡣
//
//58 2017�������
//��Ŀ��С����������ҫĿǰս����Ϊc��ÿ����������n�����֣�ս�����ֱ�Ϊs1,s2...sn
//��С��ս��������������֣�С����ս��������Ŀǰ�����Ķ��ֵ�ս�������Լ���ǰս���������Լ��
//��С����ս���������������Ҳ��ȡʤ������Ŀǰ���������ж��ֵ�ս�����ľ�ֵ
//������С����ս����


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

