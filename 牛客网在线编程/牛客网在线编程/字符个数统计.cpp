/******************************************************************************
题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
输入描述:
输入N个字符，字符在ACSII码范围内。
输出描述:
输出范围在(0~127)字符的个数。
示例1
输入
abc
输出
3
*******************************************************************************/

#include<iostream>
#include<string>
#include<set>

using namespace std;

int calculateNumber(string &str)
{
	set<char> tmp;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		tmp.insert(*it);
	}
	return tmp.size();
}

int main()
{
	string str;
	cin >> str;
	cout << calculateNumber(str) << endl;
	return 0;
}