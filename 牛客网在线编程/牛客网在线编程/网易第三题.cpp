/*

���һ��01��������������λ�õ��ַ����ǲ�һ����,���Ǿͽ����01��Ϊ����01��������: "1","10101","0101010"���ǽ���01����
С��������һ��01��s,С�����ҳ�һ����������Ӵ�,��������Ӵ���һ������01����С����Ҫ����æ�������������Ӵ��ĳ����Ƕ��١�
��������:
��������ַ���s,s�ĳ���length(1 �� length �� 50),�ַ�����ֻ����'0'��'1'


�������:
���һ������,��ʾ�������Ҫ����Ӵ����ȡ�

��������1:
111101111

�������1:
3*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int maxcount = 0;
		int count = 1;
		for (string::size_type i = 0; i < str.size()-1; i++)
		{
			
			if (str[i] != str[i + 1])
			{
				count++;
			}
			else
			{
				count = 1;
			}
			if (count > maxcount)
			{
				maxcount = count;
			}
		}

		cout << maxcount << endl;
	}

	return 0;
}