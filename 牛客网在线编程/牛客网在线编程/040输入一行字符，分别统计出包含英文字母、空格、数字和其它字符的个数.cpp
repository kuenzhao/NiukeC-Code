/*
题目描述

输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数。



**
* 统计出英文字母字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*
public static int getEnglishCharCount(String str)
{
	return 0;
}

**
* 统计出空格字符的个数。
*
* @param str 需要输入的字符串
* @return 空格的个数
*
public static int getBlankCharCount(String str)
{
	return 0;
}

**
* 统计出数字字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*
public static int getNumberCharCount(String str)
{
	return 0;
}

**
* 统计出其它字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*
public static int getOtherCharCount(String str)
{
	return 0;
}




输入描述:

输入一行字符串，可以有空格

输出描述 :

统计其中英文字符，空格字符，数字字符，其他字符的个数

示例1
输入

1qazxsw23 edcvfr45tgbn hy67uj m, ki89ol.\\ / ; p0 -= \\][

	输出

		26
		3
		10
		12

*/

#include<iostream>
#include<string>

using namespace std;

/**
* 统计出英文字母字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*/
int getEnglishCharCount(string str)
{
	int count = 0;
	for (string::size_type i = 0; i < str.size(); i++)
	{
		if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
		{
			count++;
		}
	}
	return count;
}

/**
* 统计出空格字符的个数。
*
* @param str 需要输入的字符串
* @return 空格的个数
*/
int getBlankCharCount(string str)
{
	int count = 0;
	for (string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

/**
* 统计出数字字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*/
int getNumberCharCount(string str)
{
	int count = 0;
	for (string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			count++;
		}
	}
	return count;
}

/**
* 统计出其它字符的个数。
*
* @param str 需要输入的字符串
* @return 英文字母的个数
*/
int getOtherCharCount(string str)
{
	int count = 0;
	for (string::size_type i = 0; i < str.size(); i++)
	{
		if (!(((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')) || (str[i] >= '0'&&str[i] <= '9') || (str[i] == ' ')))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << getEnglishCharCount(str) << endl;
		cout << getBlankCharCount(str) << endl;
		cout << getNumberCharCount(str) << endl;
		cout << getOtherCharCount(str) << endl;
	}
	return 0;
}