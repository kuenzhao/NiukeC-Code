/*
ţţϲ���ַ���,�����������ª���ַ���������ţţ��˵,һ���ַ����ĳ�ªֵ���ַ�������ͬ�����ַ��Եĸ����������ַ�����ABABAABBB���ĳ�ªֵ��3,��Ϊ��һ��"AA"�������ص���"BB"�����ڸ���һ���ַ���,�ַ����а����ַ�'A'��'B'��'?'��ţţ���ڿ��԰��ַ����е��ʺŸ�Ϊ'A'����'B'��ţţ���������ַ����ĳ�ªֵ��С,ϣ�����ܰ������
��������:

�������һ���ַ���s,�ַ�������length(1 �� length �� 50),�ַ���ֻ����'A','B','?'�����ַ���



�������:

���һ������,��ʾ��С�ĳ�ªֵ


��������1:

A?A


�������1:

0
*/

#include <iostream>
#include<string>
using namespace std;


int main()
{
	string str;
	cin >> str;
	int nSize = str.length();
	if (nSize<2)
	{
		cout << 0 << endl;
		return 0;
	}
	int nCount = 0;
	int ii = 0;
	//����ͷΪ�������
	while (ii<nSize && str[ii] == '?')
		ii++;
	//���ǡ�����
	if (ii == nSize)
	{
		cout << 0 << endl;
		return 0;
	}

	for (; ii<nSize - 1; ++ii)
	{
		if (str[ii] == '?')
		{
			str[ii] = str[ii - 1] == 'A' ? 'B' : 'A';
		}
		if (str[ii] == str[ii + 1])
			nCount++;
	}
	cout << nCount << endl;
}