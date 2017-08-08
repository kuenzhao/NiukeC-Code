/**********************************************************************************
题目描述
密码要求:
1.长度超过8位
2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有相同长度超2的子串重复
说明:长度超过2的子串

输入描述:
一组或多组长度超过2的子符串。每组占一行
输出描述:
如果符合要求输出：OK，否则输出NG

示例1
输入
021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000
输出
OK
NG
NG
OK
**************************************************************************************/

/*************************************************************************************
解题思路  1.首先判断字符串的长度，长度小于等于8，输出NG
2.判断字符串中是否包含大写字母，小写字母，数字，以及其他符号
3.判断是否有长度超过2的相同子串
**************************************************************************************/

#include <iostream>
#include<string>

using namespace std;
//判断字符串的长度是否超过8
bool LengthValid(string str)
{
	return str.size()>8;
}
//判断是否含有三种及其以上的字符
bool ThreeSymbolsValid(string str)
{
	bool upperLetter = false;
	bool lowerLetter = false;
	bool digital = false;
	bool otherSymbol = false;
	int count = 0;
	string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			upperLetter = true;
		}
		else if (*it >= 'a' && *it <= 'z')
		{
			lowerLetter = true;
		}
		else if (*it >= '0' && *it <= '9')
		{
			digital = true;
		}
		else {
			otherSymbol = true;
		}
	}
	if (upperLetter)
	{
		count++;
	}
	if (lowerLetter)
	{
		count++;
	}
	if (digital)
	{
		count++;
	}
	if (otherSymbol)
	{
		count++;
	}
	return (count >= 3);
	//这是别人写的，看起来比我写的简单得多，我写的有些复杂了
	/*int flag[4] = { 0 };
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') flag[0] = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z') flag[1] = 1;
		else if (str[i] >= '0' && str[i] <= '9') flag[2] = 1;
		else flag[3] = 1;
		}
	if (flag[0] + flag[1] + flag[2] + flag[3] < 3) return false;
	return true;*/

}
//判断字符串中是否有相同的子串
bool sameSubstring(string str)
{
	for (int i = 0; i <= str.size() - 6; i++)
	{
		for (int j = i + 3; j < str.size(); j++)
		{
			if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	string str;
	while (cin >> str)
	{
		if (LengthValid(str) && ThreeSymbolsValid(str) && sameSubstring(str) == false)
		{
			cout << "OK" << endl;
		}
		else {
			cout << "NG" << endl;
		}
	}
	
	return 0;
}

