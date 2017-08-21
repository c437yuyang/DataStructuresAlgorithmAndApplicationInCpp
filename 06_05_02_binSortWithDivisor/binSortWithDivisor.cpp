#include<iostream>

//������ʵ���ǻ�������

using namespace std;
int a[] = { 1,255,8,6,25,47,14,35,58,75,96,158,657 };
const int len = sizeof(a) / sizeof(int);
int b[10][len + 1] = { 0 };//��bȫ����0
void bucketSort(int a[]);//Ͱ������
void distributeElments(int a[], int b[10][len + 1], int digits);
void collectElments(int a[], int b[10][len + 1]);
int numOfDigits(int a[]);
void zeroBucket(int b[10][len + 1]);//��b�����е�ȫ��Ԫ����0
int main()
{
	cout << "ԭʼ���飺";
	for (int i = 0; i < len; i++)
		cout << a[i] << ",";
	cout << endl;
	bucketSort(a);
	cout << "��������飺";
	for (int i = 0; i < len; i++)
		cout << a[i] << ",";
	cout << endl;
	return 0;
}
void bucketSort(int a[])
{
	int digits = numOfDigits(a);
	for (int i = 1; i <= digits; i++)
	{
		distributeElments(a, b, i);
		collectElments(a, b);
		if (i != digits) //���һ�ξͲ����ڹ�����
			zeroBucket(b);
	}
}
int numOfDigits(int a[])
{
	int largest = 0;
	for (int i = 0; i < len; i++)//��ȡ���ֵ
		if (a[i] > largest)
			largest = a[i];
	int digits = 0;//digitsΪ���ֵ��λ��
	while (largest)
	{
		digits++;
		largest /= 10;
	}
	return digits;
}
void distributeElments(int a[], int b[10][len + 1], int digits)
{
	int divisor = 10;//����
	for (int i = 1; i < digits; i++)
		divisor *= 10;
	for (int j = 0; j < len; j++)
	{
		int numOfDigist = (a[j] % divisor - a[j] % (divisor / 10)) / (divisor / 10); //ȡa[j]�ĵ�digitsλ��
		//numOfDigitsΪ��Ӧ��(divisor/10)λ��ֵ,�統divisor=10ʱ,����Ǹ�λ��
		int num = ++b[numOfDigist][0];//��b�е�һ�е�Ԫ��������ÿ����Ԫ�صĸ���
		b[numOfDigist][num] = a[j];
	}
}
void collectElments(int a[], int b[10][len + 1])
{
	int k = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 1; j <= b[i][0]; j++)
			a[k++] = b[i][j];
}
void zeroBucket(int b[10][len + 1])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < len + 1; j++)
			b[i][j] = 0;
}