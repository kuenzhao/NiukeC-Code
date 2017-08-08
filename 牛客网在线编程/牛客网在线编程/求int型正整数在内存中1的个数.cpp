/******************************************************************************************
题目描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
输入描述:
输入一个整数（int类型）
输出描述:
这个数转换成2进制后，输出1的个数
示例1
输入
5
输出
2
*******************************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int inputNumber;
	cin >> inputNumber;
	int count = 0;
	while (inputNumber)
	{
		if (inputNumber % 2 != 0)
		{
			count++;
		}
		inputNumber /= 2;
	}
	cout << count << endl;
	return 0;
}