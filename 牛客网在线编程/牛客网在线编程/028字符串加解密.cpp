/****************************************************************************
��Ŀ����
1����������ַ������мӽ��ܣ��������
2���ܷ���Ϊ��
��������Ӣ����ĸʱ���ø�Ӣ����ĸ�ĺ�һ����ĸ�滻��ͬʱ��ĸ�任��Сд,����ĸaʱ���滻ΪB����ĸZʱ���滻Ϊa��
������������ʱ��Ѹ����ּ�1����0�滻1��1�滻2��9�滻0��
�����ַ������仯��
3�����ܷ���Ϊ���ܵ�����̡�
�ӿ�������
ʵ�ֽӿڣ�ÿ���ӿ�ʵ��1������������
void Encrypt (char aucPassword[], char aucResult[])���ڸú�����ʵ���ַ������ܲ����
˵����
1���ַ�����\0��β��
2���ַ����100���ַ���
int unEncrypt (char result[], char password[])���ڸú�����ʵ���ַ������ܲ����
˵����
1���ַ�����\0��β��
2���ַ����100���ַ���
��������:
����˵��
����һ��Ҫ���ܵ�����
����һ���ӹ��ܵ�����
�������:
���˵��
������ܺ���ַ�
������ܺ���ַ�
ʾ��1
����
abcdefg
BCDEFGH
���
BCDEFGH
abcdefg
*****************************************************************************/
#include<iostream>
#include<string>

using namespace std;

void Encrypt(string &aucPassword, string &aucResult)
{
	for (int i = 0; i < aucPassword.length(); i++)
	{
		if (aucPassword[i] >= 'A'&&aucPassword[i] < 'Z')
		{
			aucResult += aucPassword[i] + 33;
		}
		else if (aucPassword[i] == 'Z')
		{
			aucResult += 'a';
		}
		else if (aucPassword[i] >= 'a'&&aucPassword[i] < 'z')
		{
			aucResult += aucPassword[i] - 31;
		}
		else if (aucPassword[i] == 'z')
		{
			aucResult += 'A';
		}
		else if (aucPassword[i] >= '0'&&aucPassword[i] < '9')
		{
			aucResult += aucPassword[i] + 1;
		}
		else if (aucPassword[i] == '9')
		{
			aucResult += '0';
		}
	}
}

int unEncrypt(string &result, string &password)
{
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] > 'A'&&result[i] <= 'Z')
		{
			password += result[i] + 31;
		}
		else if (result[i] == 'A')
		{
			password += 'z';
		}
		else if (result[i] > 'a'&&result[i] <= 'z')
		{
			password += result[i] - 33;
		}
		else if (result[i] == 'a')
		{
			password += 'Z';
		}
		else if (result[i] > '0'&&result[i] <= '9')
		{
			password += result[i] - 1;
		}
		else if (result[i] == '0')
		{
			password += '9';
		}
	}
	return 0;
}
int main14()
{
	string str;
	string str1;
	string aucResult;
	string password;
	while (cin >> str >> str1)
	{
		Encrypt(str, aucResult);	
		unEncrypt(str1, password);
		cout << aucResult << endl;
		cout << password << endl;
	}
	return 0;
}