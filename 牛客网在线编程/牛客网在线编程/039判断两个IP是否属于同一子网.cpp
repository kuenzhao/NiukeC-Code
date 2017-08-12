/**
题目描述

子网掩码是用来判断任意两台计算机的IP地址是否属于同一子网络的根据。
子网掩码与IP地址结构相同，是32位二进制数，其中网络号部分全为“1”和主机号部分全为“0”。利用子网掩码可以判断两台主机是否中同一子网中。若两台主机的IP地址分别与它们的子网掩码相“与”后的结果相同，则说明这两台主机在同一子网中。

示例：
I P 地址　 192.168.0.1
子网掩码　 255.255.255.0

转化为二进制进行运算：

I P 地址　11010000.10101000.00000000.00000001
子网掩码　11111111.11111111.11111111.00000000

AND运算
11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0



I P 地址　 192.168.0.254
子网掩码　 255.255.255.0


转化为二进制进行运算：

I P 地址　11010000.10101000.00000000.11111110
子网掩码　11111111.11111111.11111111.00000000

AND运算
11000000.10101000.00000000.00000000

转化为十进制后为：
192.168.0.0

通过以上对两台计算机IP地址与子网掩码的AND运算后，我们可以看到它运算结果是一样的。均为192.168.0.0，所以这二台计算机可视为是同一子网络。


* 功能: 判断两台计算机IP地址是同一子网络。
* 输入参数：    String Mask: 子网掩码，格式：“255.255.255.0”；
*               String ip1: 计算机1的IP地址，格式：“192.168.0.254”；
*               String ip2: 计算机2的IP地址，格式：“192.168.0.1”；
*

* 返回值：      0：IP1与IP2属于同一子网络；     1：IP地址或子网掩码格式非法；    2：IP1与IP2不属于同一子网络

public int checkNetSegment(String mask, String ip1, String ip2)
{
	//在这里实现功能
	return 0;
}


输入描述:

输入子网掩码、两个ip地址

输出描述 :

得到计算结果

示例1
输入

255.255.255.0 192.168.224.256 192.168.10.4

输出

1
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
bool IsValidIp(char* str)
{
	if (str == NULL)
	{
		return false;
	}
	unsigned short a[40];
	if (sscanf(str, "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]) != 4)
	{
		return false;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (a[i] < 0 || a[i] > 255)
		{
			return false;
		}
	}
	return true;
}
int IPToValue(const string& strIP)
{
	//IP转化为数值  
	//没有格式检查  
	//返回值就是结果  

	int a[4];
	string IP = strIP;
	string strTemp;
	size_t pos;
	size_t i = 3;
	do
	{
		pos = IP.find(".");
		if (pos != string::npos)
		{
			strTemp = IP.substr(0, pos);
			a[i] = atoi(strTemp.c_str());
			i--;
			IP.erase(0, pos + 1);
		}
		else
		{
			strTemp = IP;
			a[i] = atoi(strTemp.c_str());
			break;
		}
	} while (1);

	int nResult = (a[3] << 24) + (a[2] << 16) + (a[1] << 8) + a[0];
	return nResult;
}

string ValueToIP(const int& nValue)
{
	//数值转化为IP  
	//没有格式检查  
	//返回值就是结果  
	char strTemp[20];
	sprintf(strTemp, "%d.%d.%d.%d",
		(nValue & 0xff000000) >> 24,
		(nValue & 0x00ff0000) >> 16,
		(nValue & 0x0000ff00) >> 8,
		(nValue & 0x000000ff));

	return string(strTemp);
}
int main()
{
	char mask[32] = {};
	char str1[32] = {};
	char str2[32] = {};
	while(cin >> mask >> str1>>str2)
	{
		
		if (IsValidIp(mask)&& (IPToValue(mask) | (IPToValue(mask) - 1) == 0xFFFFFFFF)&& (IsValidIp(str1) && IsValidIp(str2)))
		{
			if ((IPToValue(mask) & IPToValue(str1)) == (IPToValue(str2)&IPToValue(mask)))
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
		else
		{
			cout << 1 << endl;
		}
		
	}
}

//学习字符串的使用
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int mask1 = 0, mask2 = 0, mask3 = 0, mask4 = 0;
	char ch;
	string inputstr;
	stringstream ss;
	while (cin >> inputstr)
	{

		int ip1a = 0, ip1b = 0, ip1c = 0, ip1d = 0;
		int ip2a = 0, ip2b = 0, ip2c = 0, ip2d = 0;
		ss << inputstr;
		ss >> mask1 >> ch >> mask2 >> ch >> mask3 >> ch >> mask4;
		ss.clear();
		cin >> inputstr;
		ss << inputstr;
		ss >> ip1a >> ch >> ip1b >> ch >> ip1c >> ch >> ip1d;
		ss.clear();
		cin >> inputstr;
		ss << inputstr;
		ss >> ip2a >> ch >> ip2b >> ch >> ip2c >> ch >> ip2d;
		ss.clear();
		if ((mask1 > 255 || mask1 < 0) || (mask2 > 255 || mask2 < 0) || (mask3 > 255 || mask3 < 0) || (mask4 > 255 || mask4 < 0)
			|| (ip1a > 255 || ip1a < 0) || (ip1b > 255 || ip1b < 0) || (ip1c > 255 || ip1c < 0) || (ip1d > 255 || ip1d < 0)
			|| (ip2a > 255 || ip2a < 0) || (ip2b > 255 || ip2b < 0) || (ip2c > 255 || ip2c < 0) || (ip2d > 255 || ip2d < 0))
			cout << 1 << endl;
		else if (((mask1 & ip1a) == (mask1 & ip2a)) && ((mask2 & ip1b) == (mask2 & ip2b)) && ((mask3 & ip1c) == (mask3 & ip2c)) && ((mask4 & ip1d) == (mask4 & ip2d)))
			cout << 0 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}