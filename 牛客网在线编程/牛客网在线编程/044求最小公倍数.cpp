/*
��Ŀ����

������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
��������:
0 
��������������A��B��
�������:
���A��B����С��������
ʾ��1
����
5
7
���
35
*/

//շת�����ʵ�� 
int Division(int a ,int b) {
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;

	}
	while (a%b != 0) {
		temp = a%b;
		a = b;
		b = temp;
	}
	return b;
}
//�����ʵ�� 
int Subtract(int a,int b) {
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (a - b != 0) {
		temp = a - b;
		a = b;
		b = temp;
	}
	return b;
}
//��ٷ�ʵ�� 
int Exhaus(int a,int b) {
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	for (temp = b; a%temp || b%temp; temp--);
	return temp;
}

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		cout << num1 * num2 / Division(num1, num2) << endl;
	}
	return 0;
}