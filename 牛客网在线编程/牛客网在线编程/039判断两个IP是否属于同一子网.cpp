/**
��Ŀ����

���������������ж�������̨�������IP��ַ�Ƿ�����ͬһ������ĸ��ݡ�
����������IP��ַ�ṹ��ͬ����32λ������������������Ų���ȫΪ��1���������Ų���ȫΪ��0��������������������ж���̨�����Ƿ���ͬһ�����С�����̨������IP��ַ�ֱ������ǵ����������ࡰ�롱��Ľ����ͬ����˵������̨������ͬһ�����С�

ʾ����
I P ��ַ�� 192.168.0.1
�������롡 255.255.255.0

ת��Ϊ�����ƽ������㣺

I P ��ַ��11010000.10101000.00000000.00000001
�������롡11111111.11111111.11111111.00000000

AND����
11000000.10101000.00000000.00000000

ת��Ϊʮ���ƺ�Ϊ��
192.168.0.0



I P ��ַ�� 192.168.0.254
�������롡 255.255.255.0


ת��Ϊ�����ƽ������㣺

I P ��ַ��11010000.10101000.00000000.11111110
�������롡11111111.11111111.11111111.00000000

AND����
11000000.10101000.00000000.00000000

ת��Ϊʮ���ƺ�Ϊ��
192.168.0.0

ͨ�����϶���̨�����IP��ַ�����������AND��������ǿ��Կ�������������һ���ġ���Ϊ192.168.0.0���������̨���������Ϊ��ͬһ�����硣


* ����: �ж���̨�����IP��ַ��ͬһ�����硣
* ���������    String Mask: �������룬��ʽ����255.255.255.0����
*               String ip1: �����1��IP��ַ����ʽ����192.168.0.254����
*               String ip2: �����2��IP��ַ����ʽ����192.168.0.1����
*

* ����ֵ��      0��IP1��IP2����ͬһ�����磻     1��IP��ַ�����������ʽ�Ƿ���    2��IP1��IP2������ͬһ������

public int checkNetSegment(String mask, String ip1, String ip2)
{
	//������ʵ�ֹ���
	return 0;
}


��������:

�����������롢����ip��ַ

������� :

�õ�������

ʾ��1
����

255.255.255.0 192.168.224.256 192.168.10.4

���

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
	//IPת��Ϊ��ֵ  
	//û�и�ʽ���  
	//����ֵ���ǽ��  

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
	//��ֵת��ΪIP  
	//û�и�ʽ���  
	//����ֵ���ǽ��  
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

//ѧϰ�ַ�����ʹ��
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