/*
��Ŀ����
Lily�Ͽ�ʱʹ����ĸ����ͼƬ��С������ѧϰӢ�ﵥ�ʣ�ÿ�ζ���Ҫ����ЩͼƬ���մ�С��ASCII��ֵ��С���������պá����Ҹ�Lily��æ��ͨ��C���Խ����


�������� :
Lilyʹ�õ�ͼƬ����"A"��"Z"��"a"��"z"��"0"��"9"��������ĸ�����ָ���������1024��
������� :
Lily������ͼƬ���մ�С�����˳�����
ʾ��1
����

Ihave1nose2hands10fingers
���

0112Iaadeeefghhinnnorsssv
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main19()
{
	string str;
	while (cin >> str)
	{
		sort(str.begin(),str.end());
		cout << str << endl;
	}

	return 0;
}