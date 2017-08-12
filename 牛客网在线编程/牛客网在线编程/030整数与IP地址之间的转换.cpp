/***************************************************************************
��Ŀ����

ԭ��ip��ַ��ÿ�ο��Կ�����һ��0-255����������ÿ�β�ֳ�һ����������ʽ���������
Ȼ��������������ת���һ����������
������һ��ip��ַΪ10.0.3.193
ÿ������             ���Ӧ�Ķ�������
10                   00001010
0                    00000000
3                    00000011
193                  11000001
���������Ϊ��00001010 00000000 00000011 11000001,ת��Ϊ10���������ǣ�167773121������IP��ַת��������־������ˡ�
��ÿ�ο��Կ�����һ��0-255����������Ҫ��IP��ַ����У��
��������:
����
1 ����IP��ַ
2 ����10�����͵�IP��ַ
�������:
���
1 ���ת����10���Ƶ�IP��ַ
2 ���ת�����IP��ַ
ʾ��1
����
10.0.3.193
167969729
���
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
	stream << str;     //��stream�в����ַ���"1234" 
	stream >> n;     //��stream����ȡ�ղ�����ַ���"1234"  �����丳�����n����ַ�����int��ת�� 
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
	stream << number;     //��stream�в���������1234 
	stream >> str;     //��steam����ȡ�ղ����������   �����丳�����str�����������string��ת�� 
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