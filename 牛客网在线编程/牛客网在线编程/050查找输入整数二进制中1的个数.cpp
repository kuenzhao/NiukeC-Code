/*
题目描述

请实现如下接口

public   static   int  findNumberOf1( int num)

{

请实现  

return  0;

	} 譬如：输入5 ，5的二进制为101，输出2



	涉及知识点：
		输入描述 :

	输入一个整数

		输出描述 :

	计算整数二进制中1的个数

		示例1
		输入

		5

		输出

		2


*/
#include<iostream>
using namespace std;
int BitCount2(unsigned int n)
{
	unsigned int c = 0;
	for (c = 0; n; ++c)
	{
		n &= (n - 1); // 清除最低位的1
	}
	return c;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << BitCount2(num) << endl;
	}
	return 0;
}