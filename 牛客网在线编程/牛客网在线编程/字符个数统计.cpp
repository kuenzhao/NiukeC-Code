/******************************************************************************
��Ŀ����
��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ���ACSII�뷶Χ��(0~127)�����ڷ�Χ�ڵĲ���ͳ�ơ�
��������:
����N���ַ����ַ���ACSII�뷶Χ�ڡ�
�������:
�����Χ��(0~127)�ַ��ĸ�����
ʾ��1
����
abc
���
3
*******************************************************************************/

#include<iostream>
#include<string>
#include<set>

using namespace std;

int calculateNumber(string &str)
{
	set<char> tmp;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		tmp.insert(*it);
	}
	return tmp.size();
}

int main()
{
	string str;
	cin >> str;
	cout << calculateNumber(str) << endl;
	return 0;
}