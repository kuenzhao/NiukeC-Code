/*
题目描述

正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入描述:
0 
输入两个正整数A和B。
输出描述:
输出A和B的最小公倍数。
示例1
输入
5
7
输出
35
*/

//辗转相除法实现 
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
//相减法实现 
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
//穷举法实现 
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