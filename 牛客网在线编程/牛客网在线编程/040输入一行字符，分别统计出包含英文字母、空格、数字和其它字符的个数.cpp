/*
��Ŀ����

����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����



**
* ͳ�Ƴ�Ӣ����ĸ�ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
*
public static int getEnglishCharCount(String str)
{
	return 0;
}

**
* ͳ�Ƴ��ո��ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return �ո�ĸ���
*
public static int getBlankCharCount(String str)
{
	return 0;
}

**
* ͳ�Ƴ������ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
*
public static int getNumberCharCount(String str)
{
	return 0;
}

**
* ͳ�Ƴ������ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
*
public static int getOtherCharCount(String str)
{
	return 0;
}




��������:

����һ���ַ����������пո�

������� :

ͳ������Ӣ���ַ����ո��ַ��������ַ��������ַ��ĸ���

ʾ��1
����

1qazxsw23 edcvfr45tgbn hy67uj m, ki89ol.\\ / ; p0 -= \\][

	���

		26
		3
		10
		12

*/

#include<iostream>
#include<string>

using namespace std;

/**
* ͳ�Ƴ�Ӣ����ĸ�ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
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
* ͳ�Ƴ��ո��ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return �ո�ĸ���
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
* ͳ�Ƴ������ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
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
* ͳ�Ƴ������ַ��ĸ�����
*
* @param str ��Ҫ������ַ���
* @return Ӣ����ĸ�ĸ���
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