/*
С����һЩ��ɫ��ש�顣ÿ����ɫ��һ����д��ĸ��ʾ��������ɫש�鿴��������ȫһ����������һ���������ַ���s,s��ÿ���ַ�����С�׵�ĳ��ש�����ɫ��С����������е�ש���ų�һ�С����������һ�Բ�ͬ��ɫ������ש��,��ô����ש��ͺ�Ư���ġ��������С�׼����ж����ַ�ʽ��������ש���ų�Ư����һ�С�(������ַ�ʽ����Ӧ��ש����ɫ��������ͬ��,��ô��Ϊ�����ַ�ʽ��һ���ġ�)
����: s = "ABAB",��ôС�����������еĽ��:
"AABB","ABAB","ABBA","BAAB","BABA","BBAA"
����ֻ��"AABB"��"BBAA"�������ֻ��һ�Բ�ͬ��ɫ������ש�顣
��������:
�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),s�е�ÿһ���ַ���Ϊһ����д��ĸ(A��Z)��


�������:
���һ������,��ʾС�׿����ж����ַ�ʽ��

��������1:
ABAB

�������1:
2
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{

		int count = 0;

		char hash[26] = { 0 };

		for (string::size_type i = 0; i < str.size(); i++)
		{
			hash[str[i] - 'A']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (hash[i])
			{
				count++;
			}
		}

		if (count > 2)
		{
			cout << 0 << endl;
		}
		else if (count == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
	return 0;
}