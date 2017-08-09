/***************************************************************************
题目描述

原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，
然后把这个二进制数转变成一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001
组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。
的每段可以看成是一个0-255的整数，需要对IP地址进行校验
输入描述:
输入
1 输入IP地址
2 输入10进制型的IP地址
输出描述:
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址
示例1
输入
10.0.3.193
167969729
输出
167773121
10.3.3.193
****************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
unsigned int StrToDecimal(string str)
{
	stringstream stream;
	unsigned int n;
	stream << str;     //向stream中插入字符串"1234" 
	stream >> n;     //从stream中提取刚插入的字符串"1234"  并将其赋予变量n完成字符串到int的转换 
	return n;
}
unsigned int IPToDecimal(string str)
{
	string tmp;
	int num = 256 * 256 * 256;
	unsigned int result = 0;
	for (unsigned long i = 0; i <= str.size(); i++)
	{
		if (str[i] == '.'|| i == (str.size()))
		{
			int a = StrToDecimal(tmp);
			result += a * num;
			num /= 256;
			tmp.clear();
		}
		else
		{
			tmp += str[i];
		}
	}
	return result;
}
string NumberToStr(int number)
{
	string str;
	stringstream stream;
	stream << number;     //向stream中插入整型数1234 
	stream >> str;     //从steam中提取刚插入的整型数   并将其赋予变量str完成整型数到string的转换 
	return str+'.';
}
string DecimalToIP(unsigned int number)
{
	string str;
	bool tmp[32];
	int num = 1;
	
	for (int i = 4; i > 0; i--)
	{
		int a = 128;
		int result = 0;
		for (int j = 0; j < 8; j++)
		{
			if ((number & (num << (i * 8 - j - 1))))
			{
				result += num*a;
			}
			a /= 2;
		}
		str += NumberToStr(result);
	}
	return str.substr(0,str.size() - 1);
}

int main18()
{
	string str1,str2;
	
	while (cin >> str1 >> str2)
	{
		cout << IPToDecimal(str1) << endl;
		cout<< DecimalToIP(StrToDecimal(str2)) << endl;
	}

	return 0;
}