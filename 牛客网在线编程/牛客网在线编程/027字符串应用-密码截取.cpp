/****************************************************************************
��Ŀ����
Catcher ��MCA�����鱨Ա��������ʱ���ֵй�����һЩ�ԳƵ��������ͨ�ţ���������ЩABBA��
ABA��A��123321������������ʱ���ڿ�ʼ�����ʱ����һЩ�޹ص��ַ��Է�ֹ����ƽ⡣�����
�����б仯 ABBA->12ABBA,ABA->ABAKK,123321->51233214������Ϊ�ػ�Ĵ�̫���ˣ����Ҵ��ڶ�
�ֿ��ܵ������abaaab�ɿ�����aba,��baaab�ļ�����ʽ����Cathcer�Ĺ�����ʵ����̫���ˣ���
ֻ������Ը������������ܰ�Catcher�ҳ������Ч���봮��
��������:
����һ���ַ���
�������:
������Ч���봮����󳤶�
ʾ��1
����
ABBA
���
4
*****************************************************************************/
#include<iostream>
#include<string>
using namespace std;
int findLongestPalindrome(string &s)
{
	const int length = s.size();
	int maxlength = 0;
	int start;

	for (int i = 0; i<length; i++)//����Ϊ����  
	{
		int j = i - 1, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}

	for (int i = 0; i<length; i++)//����Ϊż��  
	{
		int j = i, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}
	
	return maxlength;
}
int main()
{
	string str;
	while (cin >> str)
	{
		cout << findLongestPalindrome(str) << endl;
	}
	return 0;
}
