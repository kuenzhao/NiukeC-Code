/**********************************************************************************
��Ŀ����
����Ҫ��:
1.���ȳ���8λ
2.������Сд��ĸ.����.��������,����������������
3.��������ͬ���ȳ�2���Ӵ��ظ�
˵��:���ȳ���2���Ӵ�

��������:
һ�����鳤�ȳ���2���ӷ�����ÿ��ռһ��
�������:
�������Ҫ�������OK���������NG

ʾ��1
����
021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000
���
OK
NG
NG
OK
**************************************************************************************/

/*************************************************************************************
����˼·  1.�����ж��ַ����ĳ��ȣ�����С�ڵ���8�����NG
2.�ж��ַ������Ƿ������д��ĸ��Сд��ĸ�����֣��Լ���������
3.�ж��Ƿ��г��ȳ���2����ͬ�Ӵ�
**************************************************************************************/

#include <iostream>
#include<string>

using namespace std;
//�ж��ַ����ĳ����Ƿ񳬹�8
bool LengthValid(string str)
{
	return str.size()>8;
}
//�ж��Ƿ������ּ������ϵ��ַ�
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
	//���Ǳ���д�ģ�����������д�ļ򵥵ö࣬��д����Щ������
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
//�ж��ַ������Ƿ�����ͬ���Ӵ�
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

