/*
ţţ��n�ſ�Ƭ�ų�һ������.ÿ�ſ�Ƭһ���Ǻ�ɫ��,��һ���ǰ�ɫ�ġ���ʼ״̬��ʱ����Щ��Ƭ�Ǻ�ɫ����,��Щ��Ƭ�ǰ�ɫ���ϡ�ţţ������Ҫ��һЩ��Ƭ������,�õ�һ�ֽ������е���ʽ,��ÿ�����ڿ�Ƭ����ɫ���ǲ�һ���ġ�ţţ��֪��������Ҫ��ת�����ſ�Ƭ���Ա�ɽ������е���ʽ��
��������:

�������һ���ַ���S,�ַ�������length(3 �� length �� 50),����ֻ����'W'��'B'�����ַ���,�ֱ��ʾ��ɫ�ͺ�ɫ�������ַ�����ʾ��Ƭ���еĳ�ʼ״̬��



�������:

���һ������,��ʾţţ�����Ҫ��ת�Ĵ�����


��������1:

BBBW


�������1:

1
*/

#include <iostream>
#include<string>
using  namespace std;


/***********************
1.�����ĸ�����
nEvenWhite: ż��λ�ð�ɫ����
nEvenBlack: ż��λ�ú�ɫ����
nOddWhite:  ����λ�ð�ɫ����
nOddBlack:  ����λ�ú�ɫ����
2.������
��ż��λ�õİ�ɫ��Ϊ��ɫ������λ�ú�ɫ��ɰ�ɫ
������λ�õİ�ɫ��ɺ�ɫ��ż��λ�õĺ�ɫ��ɰ�ɫ
3.��������������ֽ����Сֵ
************************/
int main()
{

	string str;
	cin >> str;
	int  nCount = str.length();
	int nEvenWhite = 0;
	int nEvenBlack = 0;
	int nOddWhite = 0;
	int nOddBlack = 0;
	for (int i = 0; i<nCount; ++i)
	{
		if (i % 2)
		{
			if (str[i] == 'W')
			{
				nOddWhite++;
			}
			else
			{
				nOddBlack++;
			}
		}
		else
		{
			if (str[i] == 'W')
			{
				nEvenWhite++;
			}
			else
			{
				nEvenBlack++;
			}

		}
	}
	int ans = nEvenWhite + nOddBlack >nEvenBlack + nOddWhite ? nEvenBlack + nOddWhite : nEvenWhite + nOddBlack;

	cout << ans << endl;

}