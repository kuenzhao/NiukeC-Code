/*
СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
���ܰ��СQ��
��������:
���������ж��飬ÿ�����һ���ַ���s���ұ�֤:1<=s.length<=1000.
�������:
����ÿ�����ݣ������λ����ַ�����
��������1:
AkleBiCeilD
�������1:

kleieilABCD
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool compare(char a, char b)
{
	return a>b;   //�������У������Ϊreturn a>b����Ϊ����

}
int main()
{
	string str;

	while (cin >> str)
	{
		int tmp = str.size();
		for (string::size_type i = 0; i < tmp; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str += str[i];
			}
		}
		for (string::size_type i = 0; i < tmp; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str.erase(i, 1);
				i--;
				tmp--;
			}
		}
		cout << str << endl;
	}
	
	return 0;
}