/*
题目描述

Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：

如22：twenty two，123：one hundred and twenty three。

说明：

数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；

输出格式为twenty two；

非法数据请返回“error”；

关键字提示：and，billion，million，thousand，hundred。

方法原型：public static String parse(long num)

输入描述:

输入一个long型整数

输出描述:

输出相应的英文写法

示例1
输入

2356

输出

two thousand three hundred and fifty six
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> helper1{ "","thousand","million","billion" };
vector<string> helper2{ "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
vector<string> helper3{"","one","two","three","four","five","six","seven","eight","nine"};
vector<string> hepler4{ "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

string sound(int num)
{
	string res;
	if (num >= 0 && num <= 9)
	{
		res += helper3[num];
	}
	else if (num >= 10 && num <= 19)
	{
		res += hepler4[num % 10];
	}
	else if (num >= 20 && num <= 99)
	{
		res += helper2[num / 10];
		if (num % 10 == 0)
		{
			return res;
		}
		res += " ";
		res += helper3[num % 10];
	}
	else 
	{
		res += helper3[num / 100];
		res += " hundred";
		num %= 100;
		if (num)
		{
			res += " and ";
			res += sound(num);
		}
	}
	return res;
}

int main()
{
	long num = 0;
	while (cin >> num)
	{
		vector<int> parts;
		string res;
		if (num == 0)
		{
			cout << "zero" << endl;
			continue;
		}
		else if (num > 999999999 || num < 0)
		{
			cout << "error" << endl;
			continue;
		}
		while (num)
		{
			int tmp = num % 1000;
			parts.push_back(tmp);
			num /= 1000;
		}
		for (int i = parts.size() - 1; i >= 0; i--)
		{
			string tmp = sound(parts[i]);
			if (tmp == "")continue;
			res += tmp;
			if (i)
			{
				res += " ";
				res += helper1[i];
				res += " ";
			}
		}

		while (res[res.size() - 1] == ' ')
		{
			res.erase(res.end() - 1);
		}

		cout << res << endl;
	}
	return 0;
}