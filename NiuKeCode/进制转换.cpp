/*****************************************************************************
��Ŀ������
	д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����
	������ͬʱ���� ��
��������:
	����һ��ʮ�����Ƶ���ֵ�ַ�����
�������:
	�������ֵ��ʮ�����ַ�����
ʾ����
	����
	0xA
	���
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
	if ((str[0] == '0' && str[1] == 'x')|| (str[0] == '0' && str[1] == 'X'))//�ж�ʮ����������ͷ
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
	if ((str[0] == '0' && str[1] == 'd') || (str[0] == '0' && str[1] == 'D'))//�ж�ʮ����������ͷ
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
	if ((str[0] == '0' && str[1] == 'b') || (str[0] == '0' && str[1] == 'B'))//�ж�ʮ����������ͷ
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
int AnyToDec(string &str,int n)//�����ַ����͵�ǰ����(ת����Χ��2-16)
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
	reverse(strTmp.begin(), strTmp.end());//�ַ�����ת
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
	reverse(strTmp.begin(), strTmp.end());//�ַ�����ת
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
	reverse(strTmp.begin(), strTmp.end());//�ַ�����ת
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
	reverse(strTmp.begin(), strTmp.end());//�ַ�����ת
	strOut += strTmp;
	return strOut;
}

//������Ƶ��������֮���ת�����������䣨2-16��
string AnyToAny(string &str, int n, int m)
{
	//n��ʾ��ǰ���ƣ�m��ʾ��������
	return DecToAny(AnyToDec(str, m), n);
}

int main()
{
	string str = "90";	
	cin >> str;
	cout << DecToHex(988) << endl;
	return 0;
}