/*
��Ŀ����

����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽��

��������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣���

��4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9��

�Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ�����

���������Ħ˹����õ�Լ���ʱ�䡣


��������:

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����
�������:
��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ����
�ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣


��������:

3485djDkxh4hhGE

2984akDfkkkkggEdsb

s&hgsfdk

d&Hyscvnm


�������:

THU 14:04

*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	int size1 = str1.size() < str2.size() ? str1.size() : str2.size();
	int size2 = str3.size() < str4.size() ? str3.size() : str4.size();
	string Days[7] = { "MON", "TUE","WED", "THU", "FRI", "SAT", "SUN" };
	string outstr;
	bool flag = false;
	for (string::size_type i = 0; i < size1; i++)
	{
		if (str1[i] == str2[i] && flag == false&& (str1[i] >= 'A'&& str1[i] <= 'G'))
		{
			outstr += (Days[str1[i]-'A'] + ' ');
			flag = true;
		}
		else if(str1[i] == str2[i] && flag == true && ((str1[i] >= 'A'&& str1[i] <= 'Z')||(str1[i] >= '0'&& str1[i] <= '9')))
		{
			if (str1[i] > 'A' && str1[i] < 'N')
			{
				int time = str1[i] - 'A'+ 10;
				outstr += to_string(time) + ':';
			}
			else if(str1[i] >= '0' && str1[i] <= '9')
			{
				outstr += '0';
				outstr += str1[i];
				outstr += ':';
			}
			break;
		}
	}
	for (string::size_type i = 0; i < size2; i++)
	{
		if (str3[i] == str4[i] && ((str3[i]>='a'&& str3[i]<='z')||(str3[i] >= 'A'&& str3[i] <= 'Z')))
		{
			if (i < 10)
			{
				outstr += '0';
			}
			outstr += to_string(i);
			break;
		}
	}
	cout << outstr << endl;
	return 0;
}