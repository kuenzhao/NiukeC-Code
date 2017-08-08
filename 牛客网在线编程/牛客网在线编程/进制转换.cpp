/*****************************************************************************
题目描述：
	写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。
	（多组同时输入 ）
输入描述:
	输入一个十六进制的数值字符串。
输出描述:
	输出该数值的十进制字符串。
示例：
	输入
	0xA
	输出
	10
******************************************************************************/


#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>
using namespace std;
string num2str(long i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}
int HexToDec(string &str)
{
	int r = 0;
	if ((str[0] == '0' && str[1] == 'x')|| (str[0] == '0' && str[1] == 'X'))//判断十六进制数的头
	{
		for (unsigned int i = 2; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				r = r * 16 + str[i] - '0';
			}
			else if (str[i] >= 'A'&&str[i] <= 'F')
			{
				r = r * 16 + str[i] - 'A' + 10;
			}
			else if ((str[i] >= 'a'&&str[i] <= 'f'))
			{
				r = r * 16 + str[i] - 'a' + 10;
			}
			else
			{
				cout << "error is not Hexadecimal number" << endl;
				return -1;
			}
		}
	}
	return r;
}
int OctToDec(string &str)
{
	int r = 0;
	if ((str[0] == '0' && str[1] == 'd') || (str[0] == '0' && str[1] == 'D'))//判断十六进制数的头
	{
		for (unsigned int i = 2; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '7')
			{
				r = r * 8 + str[i] - '0';
			}
			else
			{
				cout << "error is not Binary number" << endl;
				return -1;
			}
		}
	}
	return r;
}
int BinToDec(string &str)
{
	int r = 0;
	if ((str[0] == '0' && str[1] == 'b') || (str[0] == '0' && str[1] == 'B'))//判断十六进制数的头
	{
		for (unsigned int i = 2; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '1')
			{
				r = r * 2 + str[i] - '0';
			}
			else
			{
				cout << "error is not Binary number" << endl;
				return -1;
			}
		}
	}
	return r;
}
int AnyToDec(string &str,int n)//输入字符串和当前进制(转换范围：2-16)
{
	int r = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			r = r * n + str[i] - '0';
		}
		else if (str[i] >= 'A'&&str[i] <= 'F')
		{
			r = r * n + str[i] - 'A' + 10;
		}
		else if ((str[i] >= 'a'&&str[i] <= 'f'))
		{
			r = r * n + str[i] - 'a' + 10;
		}
		else 
		{
			cout << "error is not Hexadecimal number" << endl;
			return -1;
		}
	}
	return r;
}

string DecToHex(int InNumber)
{
	string strOut = "0x";
	string strTmp;
	int tmp = 0;
	while (InNumber)
	{
		tmp = InNumber % 16;
		if (tmp > 10)
		{
			char a = tmp + 55;
			strTmp += a;
		}
		else
		{
			strTmp += num2str(tmp);
		}
		InNumber /= 16;
	}
	reverse(strTmp.begin(), strTmp.end());//字符串反转
	strOut += strTmp;
	return strOut;
}
string DecToOct(int InNumber)
{
	string strOut = "0d";
	string strTmp;
	int tmp = 0;
	while (InNumber)
	{
		tmp = InNumber % 8;
		strTmp += num2str(tmp);	
		InNumber /= 8;
	}
	reverse(strTmp.begin(), strTmp.end());//字符串反转
	strOut += strTmp;
	return strOut;
}
string DecToBin(int InNumber)
{
	string strOut = "0b";
	string strTmp;
	int tmp = 0;
	while (InNumber)
	{
		tmp = InNumber % 2;
		strTmp += num2str(tmp);
		InNumber /= 2;
	}
	reverse(strTmp.begin(), strTmp.end());//字符串反转
	strOut += strTmp;
	return strOut;
}
string DecToAny(int InNumber,int n)
{
	string strOut;
	string strTmp;
	int tmp = 0;
	while (InNumber)
	{
		tmp = InNumber % n;
		if (tmp > 10)
		{
			strTmp += num2str(tmp + 55);
		}
		else
		{
			strTmp += num2str(tmp);
		}
		InNumber /= n;
	}
	reverse(strTmp.begin(), strTmp.end());//字符串反转
	strOut += strTmp;
	return strOut;
}

//任意进制到任意进制之间的转化，进制区间（2-16）
string AnyToAny(string &str, int n, int m)
{
	//n表示当前进制，m表示期望进制
	return DecToAny(AnyToDec(str, m), n);
}

int main()
{
	string str = "90";	
	cin >> str;
	cout << DecToHex(988) << endl;
	return 0;
}