/*********************************************************************************************
��Ŀ����
����ָ�������������ַ������д���
��ϸ������
������������ַ����ϲ���
�Ժϲ�����ַ�����������Ҫ��Ϊ���±�Ϊ�������ַ����±�Ϊż�����ַ��ֱ��С��������������±�
��˼���ַ����ַ����е�λ�á����������ַ������в���������ַ�Ϊ��0��������9�����ߡ�A��������F��
���ߡ�a��������f������������������16���Ƶ�������BIT����Ĳ�������ת��Ϊ��Ӧ�Ĵ�д�ַ������ַ�Ϊ
��4����Ϊ0100b����ת��Ϊ0010b��Ҳ����2��ת������ַ�Ϊ��2���� ���ַ�Ϊ��7����Ϊ0111b����ת��Ϊ
1110b��Ҳ����e��ת������ַ�Ϊ��д��E����
����������str1Ϊ"dec"��str2Ϊ"fab"���ϲ�Ϊ��decfab�����ֱ�ԡ�dca���͡�efb����������
�����Ϊ��abcedf����ת����Ϊ��5D37BF��
�ӿ���Ƽ�˵����
����:�ַ�������
����:�����ַ���,��Ҫ�쳣����
���:�ϲ��������ַ���������Ҫ��ο��ĵ�
����:��
void ProcessString(char* str1, char *str2, char * strOutput)
{

}
��������:
���������ַ���
������� :
���ת����Ľ��
ʾ��1
����
dec fab
���
5D37BF
**************************************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char BitReverse(int a)
{
	int result = 0;
	int tmp = 8;
	int tmp2 = 1;
	for (int i = 0; i < 4; i++)
	{
		if ((a & tmp))
		{
			result += tmp2;
		}	
		tmp = tmp >> 1;
		tmp2 = tmp2 << 1;
	}

	if (result >= 0 && result <= 9)
	{
		return '0' + result;
	}
	else
	{
		return 'A' + result - 10;
	}
}
/*
����:�ַ�������
����:�����ַ���,��Ҫ�쳣����
���:�ϲ��������ַ���������Ҫ��ο��ĵ�
����:��
*/

void ProcessString(string &str1, string &str2, string &strOutput)
{
	string tmp1, tmp2, tmp3;
	tmp1 = str1 + str2;
	for (int i = 0; i < tmp1.size(); i+=2)
	{
		tmp2 += tmp1[i];
	}
	for (int i = 1; i < tmp1.size(); i += 2)
	{
		tmp3 += tmp1[i];
	}
	sort(tmp2.begin(), tmp2.end());
	sort(tmp3.begin(), tmp3.end());
	
	
	for (unsigned long i = 0; i < tmp3.size(); i++)
	{
		strOutput += tmp2[i];
		strOutput += tmp3[i];
	}
	if (tmp1.size() % 2 != 0)
	{
		strOutput += tmp2[tmp2.size() - 1];
	}
	

	for (unsigned long i = 0; i < strOutput.size(); i++)
	{
		if (strOutput[i] >= '0' && strOutput[i] <= '9')
		{
			strOutput[i] = BitReverse(strOutput[i] - '0');
		}
		else if (strOutput[i] >= 'a' && strOutput[i] <= 'f')
		{
			strOutput[i] = BitReverse(strOutput[i] - 'a'+ 10);
		}
		else if (strOutput[i] >= 'A' && strOutput[i] <= 'F')
		{
			strOutput[i] = BitReverse(strOutput[i] - 'A' + 10);
		}
	}
}
int main15()
{
	string str1,str2,strOutput;

	while (cin >> str1 >> str2)
	{
		ProcessString(str1, str2, strOutput);
		cout << strOutput <<endl;
		strOutput.clear();
	}
	
	return 0;
}