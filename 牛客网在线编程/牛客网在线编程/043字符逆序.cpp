/*
��Ŀ����

��һ���ַ���str�����ݵߵ��������������str�ĳ��Ȳ�����100���ַ��� �磺���롰I am a student���������tneduts a ma I����






���������

inputString��������ַ���




����ֵ��

���ת���õ������ַ���
��������:

����һ���ַ����������пո�

�������:

���������ַ���

ʾ��1
����

I am a student

���

tneduts a ma I
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;

	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout <<str << endl;
	}
	return 0;
}